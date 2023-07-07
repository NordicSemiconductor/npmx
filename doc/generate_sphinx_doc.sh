rm -rf html_sphinx
doxygen npmx.doxyfile
sphinx-build -b html sphinx html_sphinx -w warnings_sphinx_npmx.txt
