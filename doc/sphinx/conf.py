#!/usr/bin/env python3

from pathlib import Path
import re
from os import walk, makedirs, path
from distutils.dir_util import copy_tree

CONF_DIR = Path(__file__).absolute().parent
"""conf.py directory."""

with open(CONF_DIR / ".." / "npmx.doxyfile") as f:
    VERSION = re.search(r'PROJECT_NUMBER\s+=\s+"(.*)"', f.read()).group(1)

# Copy doxygen-generated XML files
copy_tree(str(CONF_DIR.parent / "xml"), str(CONF_DIR.parent / "html_sphinx" / "xml"))

# Creare drivers directory with .rst files
drivers_include_directory = CONF_DIR / ".." / ".." / "drivers" / "include"
driver_headers = []
for (dir_path, dir_names, headers_names) in walk(drivers_include_directory):
    driver_headers.extend([Path(dir_path) / Path(header_name) for header_name in headers_names])
    # don't look inside any subdirectory
    break

# add instance
driver_headers.append(CONF_DIR / ".." / ".." / "npmx_instance.h")

for header_path in driver_headers:
    with open(header_path) as f:
        res = re.search(r'\@defgroup\s+(.*)\s+(.*)', f.read())
        if res:
            defgroup, name = res.group(1).split()
            dir_path = CONF_DIR / "drivers" / name.lower()
            if not path.exists(dir_path):
                makedirs(dir_path)
            f = open(dir_path / "index.rst", "w")
            ret = f.write(f"""
{name}
{"".join(len(name)*["="])}

.. doxygengroup:: {defgroup}
""")
            f.close()

# General configuration --------------------------------------------------------

project = "npmx"
copyright = "2022, Nordic Semiconductor ASA"
author = "Nordic Semiconductor"
version = VERSION

extensions = ["breathe", "m2r2"]
source_suffix = {
    ".rst": "restructuredtext",
    ".md": "markdown"
}
master_doc = "index"
exclude_patterns = ["theme"]

# Options for HTML output ------------------------------------------------------

html_theme = "sphinx_ncs_theme"
html_static_path = [str(CONF_DIR / "_static")]
html_last_updated_fmt = "%b %d, %Y"
html_show_sphinx = False

# Options for Breathe ----------------------------------------------------------

breathe_projects = {"npmx": str(CONF_DIR.parent / "html_sphinx" / "xml")}
breathe_default_project = "npmx"
breathe_domain_by_extension = {"h": "c", "c": "c"}
breathe_separate_member_pages = True
