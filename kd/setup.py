from distutils.extension import Extension

from setuptools import setup
from Cython.Build import cythonize

setup(
    ext_modules=cythonize([Extension("lib", ["lib.pyx", "class.cpp"])])
)
