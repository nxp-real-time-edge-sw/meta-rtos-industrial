#!/usr/bin/env python3

import pathlib
import re
import subprocess
import sys
import urllib.parse

version = sys.argv[1]
if not version:
    raise ValueError("Please provide a valid Heterogeneous Multicore manifest version (e.g., 3.3)")

# Get project list from west list command
try:
    output = subprocess.check_output(['west', 'list', '--format', '{name}|{path}|{url}|{revision}|{sha}'],
                                   universal_newlines=True)
except subprocess.CalledProcessError as e:
    print(f"Error running 'west list': {e}")
    print("Make sure you are in a west workspace and it's properly initialized")
    sys.exit(1)

# Parse the west list output
projects = []
for line in output.strip().split('\n'):
    if not line:
        continue
    parts = line.split('|')
    if len(parts) >= 5:
        name, path, url, revision, sha = parts[:5]
        # Skip the manifest project itself
        if name == 'manifest':
            continue

        # Skip the bifrost
        if name == 'bifrost':
            continue

        # Special case: Rename CMSIS to MCUX_CMSIS to avoid conflict with cmsis
        # github.com/nxp-mcuxpresso/mcu-sdk-cmsis and github.com/zephyrproject-rtos/cmsis
        if name == 'CMSIS':
            name = 'MCUX_CMSIS'

        projects.append({
            'name': name,
            'path': path,
            'url': url,
            'revision': sha if sha else revision  # Use SHA if available
        })

# Sort projects by path for consistent output
projects.sort(key=lambda p: p['path'])

# Helper functions
def resolve_revision(revision, repo_url):
    print(f"Resolving revision: {revision} for repo: {repo_url}")
    if re.match(r'[a-f0-9]{40}', revision):
        return revision

    try:
        subprocess.check_output(['git', 'ls-remote', '--exit-code', repo_url, 'HEAD'], stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError:
        print(f"Warning: repo not found: {repo_url}, using revision as-is.")
        return revision

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
    return name.upper().replace('-', '_').replace('.', '_')

# Generate the content
short_version = '.'.join(version.split('.')[0:2])
hmc_url = 'https://github.com/nxp-real-time-edge-sw/heterogeneous-multicore.git'

# Start building the content
lines = []

# Header
lines.append("# Auto-generated from generate-version-hmc-from-west.py")
lines.append("")
lines.append('SRCREV_FORMAT = "hmc"')
lines.append("")

# Default SRCREV
default_revision = resolve_revision(f'v{version}', hmc_url)
lines.append(f'SRCREV_hmc ?= "{default_revision}"')

# Project SRCREVs
for project in projects:
    proj_revision = resolve_revision(project['revision'], project['url'])
    if proj_revision:
        lines.append(f'SRCREV_{project["name"]} ?= "{proj_revision}"')

lines.append("")

# HMC URL
lines.append(f'SRC_URI_HMC ?= "{git_url_to_bitbake(hmc_url)}"')

# Project URLs
for project in projects:
    var_name = bitbake_var(project['name'])
    lines.append(f'SRC_URI_{var_name} ?= "{git_url_to_bitbake(project["url"])}"')

lines.append("")

# Project URLs with branch
for project in projects:
    var_name = bitbake_var(project['name'])
    lines.append(f'SRC_URI_{var_name}_WITH_BRANCH ?= "${{SRC_URI_{var_name}}};nobranch=1"')

lines.append("")

# SRC_URI
lines.append('SRC_URI = "\\')
lines.append('    ${SRC_URI_HMC};branch=${HMC_BRANCH};name=hmc;destsuffix=git/heterogeneous-multicore \\')
for project in projects:
    var_name = bitbake_var(project['name'])
    lines.append(f'    ${{SRC_URI_{var_name}_WITH_BRANCH}};name={project["name"]};destsuffix=git/{project["path"]} \\')
lines.append('"')
lines.append("")

# HMC_MODULES
lines.append('HMC_MODULES = "\\')
for project in projects:
    lines.append(f'${{S}}/{project["path"]}\\;\\')
lines.append('"')
lines.append("")

# HMC_BRANCH and PV
lines.append(f'HMC_BRANCH ?= "main"')
lines.append(f'PV = "{version}"')

# Write to file
dest_path = pathlib.Path(__file__).parents[1] / 'recipes-heterogeneous-multicore' / 'hmc-source' / f'hmc-source.inc'
with open(dest_path, 'w') as f:
    f.write('\n'.join(lines))
    f.write('\n')  # Add final newline

print(f"Generated: {dest_path}")
print(f"Total projects: {len(projects)}")