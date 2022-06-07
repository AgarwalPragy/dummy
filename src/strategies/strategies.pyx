# distutils: language=c++
# cython: language_level=3

from libcpp.string cimport string
from libcpp.vector cimport vector

cdef extern from "allot_first.h":
    cdef cppclass cpp_AllotFirstSeatStrategy "AllotFirstSeatStrategy":
        string allot(vector[string])

cdef extern from "allot_last.h":
    cdef cppclass cpp_AllotLastSeatStrategy "AllotLastSeatStrategy":
        string allot(vector[string])

cdef class AllotFirstSeatStrategy:
    cdef cpp_AllotFirstSeatStrategy thisptr

    def allot(self, available_seat_numbers):
        self.thisptr.allot(available_seat_numbers)

cdef class AllotLastSeatStrategy:
    cdef cpp_AllotLastSeatStrategy thisptr

    def allot(self, available_seat_numbers):
        self.thisptr.allot(available_seat_numbers)
