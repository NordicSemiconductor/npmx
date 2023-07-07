# npmx documentation

## Doxygen

You can generate doxygen-based documentation by running it from the `doc` directory.

```shell
doxygen npmx.doxyfile
```

You may want to use the provided scripts `generate_html_doc.sh` or
`generate_html_doc.bat`. The result can be viewed by opening
`html/index.html`.

## Sphinx

You can generate Sphinx-based documentation by running it from the `doc` directory.

```shell
sphinx-build -b html sphinx html_sphinx -w warnings_sphinx_npmx.txt
```
