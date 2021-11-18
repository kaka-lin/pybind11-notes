# Installing the library

There are several ways to get the pybind11 source, which lives at [pybind/pybind11 on GitHub](https://github.com/pybind/pybind11). The pybind11 developers recommend one of the first three ways listed here, `submodule`, `PyPI`, or `conda-forge`, for obtaining pybind11.

This will provide pybind11 in a standard Python package format.

## Include as a submodule

```bash
$ git submodule add -b stable https://github.com/pybind/pybind11.git lib/pybind11
$ git submodule update --init
```

## Include as a lib

```bash
$ wget https://github.com/pybind/pybind11/archive/v2.8.1.tar.gz
$ mkdir lib
$ tar zxvf v2.8.1.tar.gz -C lib
$ mv lib/pybind11-2.8.1 lib/pybind11
$ rm v2.8.1.tar.gz
```

## Include with PyPI

```bash
$ pip install pybind11
```
