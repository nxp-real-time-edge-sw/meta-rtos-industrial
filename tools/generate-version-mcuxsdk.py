#!/usr/bin/env python3

import pathlib
import re
import subprocess
import sys
import urllib.parse
import tempfile
import shutil
import os
import yaml

# This non-standard module must be installed on the host
import west.manifest

# This script takes one argument - the MCUXSDK manifest version (e.g., 25.06.00)
version = sys.argv[1]
if not re.match(r'\d+\.\d+\.\d+', version):
    raise ValueError("Please provide a valid MCUXSDK manifest version (e.g., 25.06.00)")

# Download the manifest XML from GitHub
manifest_url = 'https://github.com/nxp-mcuxpresso/mcuxsdk-manifests.git'
tmpdir = tempfile.mkdtemp()

try:
    subprocess.check_call(['git', 'clone', '--depth', '1', '--branch', f'v{version}', manifest_url, tmpdir])
    manifest_path = os.path.join(tmpdir, 'west.yml')

    os.makedirs(os.path.join(tmpdir, '.west'), exist_ok=True)
    with open(os.path.join(tmpdir, '.west', 'config'), 'w') as f:
        f.write('[manifest]\n')
        f.write('    path = .\n')
        f.write('    file = west.yml\n')

    manifest = west.manifest.Manifest.from_topdir(topdir=tmpdir)
    all_projects = manifest.get_projects([])

    projects = [p for p in all_projects if manifest.is_active(p)]

finally:
    print(f"Cleaning up temporary directory: {tmpdir}")
    print(f"Cleaning up temporary directory: {manifest_path}")
    shutil.rmtree(tmpdir)

# projects contains a 'manifest' project for 'self' which we don't want to use
projects = list(filter(lambda project: project.name != 'manifest', projects))

# Helper functions
def resolve_revision(revision, repo_url):
    print(f"Resolving revision: {revision} for repo: {repo_url}")
    if re.match(r'[a-f0-9]{40}', revision):
        return revision

    try:
        subprocess.check_output(['git', 'ls-remote', '--exit-code', repo_url, 'HEAD'], stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError:
        print(f"Warning: repo not found: {repo_url}, skip.")
        return None

    try:
        output = subprocess.check_output(['git', 'ls-remote', '--exit-code', repo_url, f'{revision}^{{}}'])
        return output.split()[0].decode()
    except subprocess.CalledProcessError:
        try:
            output = subprocess.check_output(['git', 'ls-remote', '--exit-code', repo_url, revision])
            return output.split()[0].decode()
        except subprocess.CalledProcessError:
            print(f"Warning: could not resolve revision {revision} for {repo_url}, using as-is")
            return revision

def git_url_to_bitbake(url):
    parts = urllib.parse.urlparse(url)
    original_scheme = parts.scheme
    parts = parts._replace(scheme='git')
    return parts.geturl() + ';protocol=' + original_scheme

def bitbake_var(name):
    return name.upper().replace('-', '_')

# Generate the content
mcuxsdk_url = 'https://github.com/nxp-mcuxpresso/mcuxsdk-manifests.git'
short_version = '.'.join(version.split('.')[0:2])

# Start building the content
lines = []

# Header
lines.append("# Auto-generated from generate-version-mcuxsdk.py")
lines.append("")
lines.append('SRCREV_FORMAT = "mcuxsdk"')
lines.append("")

# Default SRCREV
default_revision = resolve_revision(f'v{version}', mcuxsdk_url)
lines.append(f'SRCREV_mcuxsdk ?= "{default_revision}"')

# Project SRCREVs
for project in projects:
    proj_revision = resolve_revision(project.revision, project.url)
    if proj_revision:
        lines.append(f'SRCREV_mcuxsdk-{project.name} ?= "{proj_revision}"')

lines.append("")

# MCUXSDK URL
lines.append(f'SRC_URI_MCUXSDK ?= "{git_url_to_bitbake(mcuxsdk_url)}"')

# Project URLs
for project in projects:
    var_name = bitbake_var(project.name)
    lines.append(f'SRC_URI_MCUXSDK_{var_name} ?= "{git_url_to_bitbake(project.url)}"')

lines.append("")

# Project URLs with branch
for project in projects:
    var_name = bitbake_var(project.name)
    lines.append(f'SRC_URI_MCUXSDK_{var_name}_WITH_BRANCH ?= "${{SRC_URI_MCUXSDK_{var_name}}};nobranch=1"')

lines.append("")

# SRC_URI
lines.append('SRC_URI = "\\')
lines.append('    ${SRC_URI_MCUXSDK};branch=${MCUXSDK_BRANCH};name=mcuxsdk;destsuffix=git/manifests \\')
for project in projects:
    var_name = bitbake_var(project.name)
    lines.append(f'    ${{SRC_URI_MCUXSDK_{var_name}_WITH_BRANCH}};name=mcuxsdk-{project.name};destsuffix=git/{project.path} \\')
lines.append('"')
lines.append("")

# MCUXSDK_MODULES
lines.append('MCUXSDK_MODULES = "\\')
for project in projects:
    lines.append(f'${{S}}/{project.path}\\;\\')
lines.append('"')
lines.append("")

# MCUXSDK_BRANCH and PV
lines.append(f'MCUXSDK_BRANCH = "release/{version}"')
lines.append(f'PV = "{version}"')

# Output directly to the mcux-kernel directory
dest_path = pathlib.Path(__file__).parents[1] / 'recipes-mcuxsdk' / 'mcuxsdk-source' / f'mcuxsdk-source.inc'

# Generate the Bitbake include file
with open(dest_path, 'w') as f:
    f.write('\n'.join(lines))
    f.write('\n')  # Add final newline

print(f"Generated: {dest_path}")
print(f"Total projects: {len(projects)}")
