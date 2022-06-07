from distutils.extension import Extension

from setuptools import setup
from Cython.Build import cythonize

setup(
    ext_modules=cythonize([Extension("booking", [
        "booking/__init__.pyx",
        "booking/booking.cpp",
        "booking/py_booking.cpp",
        "strategies/__init__.pyx",
        "strategies/allot_first.cpp",
        "strategies/allot_last.cpp",
        ],
        language="c++",
        extra_compile_args=["-std=c++17"],
        extra_link_args=["-std=c++17"]
    )])
)
