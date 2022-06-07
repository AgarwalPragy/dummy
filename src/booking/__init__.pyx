# distutils: language=c++
# cython: language_level=3

from libcpp.string cimport string
from libcpp.vector cimport vector
from libcpp.unordered_map cimport unordered_map


cdef extern from "booking.h":
    cdef cppclass cpp_Person "Person":
        string name
        string phone_number

        bint operator==(Person)

    cdef cppclass cpp_PersonHasher "PersonHasher":
        size_t operator()(cpp_Person)


    cdef cppclass cpp_SeatType "SeatType":
        pass

    cdef cpp_SeatType DELUX
    cdef cpp_SeatType STANDARD

    cdef cppclass cpp_BookingSeat "BookingSeat":
        cpp_SeatType type
        string seat_number

        bint is_delux()

        bint is_standard()


    cdef cppclass cpp_SeatAllotmentStrategy "SeatAllotmentStrategy":
        string allot(vector[string] available_seat_numbers)


    cdef cppclass cpp_Ticket "Ticker":
        cpp_BookingSeat add(cpp_Person, vector[string], cpp_SeatAllotmentStrategy)

        void update_seats(unordered_map[cpp_Person, cpp_BookingSeat])


cdef extern from "py_booking.h":
    cdef cppclass cpp_PySeatAllotmentStrategy "PySeatAllotmentStrategy"(cpp_SeatAllotmentStrategy):
        void setInstance(SeatAllotmentStrategy)


cdef class Person:
    cdef cpp_Person thisptr

    @property
    def name(self) -> str:
        return self.thisptr.name

    @name.setter
    def name(self, name: str) -> None:
        self.thisptr.name = name

    @property
    def phone_number(self) -> str:
        return self.thisptr.phone_number

    @phone_number.setter
    def phone_number(self, phone_number: str) -> None:
        self.thisptr.phone_number = phone_number

    # def __hash__(self) -> int:
    #     return cpp_PersonHasher(self)

    # def __eq__(self, other) -> bool:
    #     if self == other: return True
    #     if not isinstance(other, Person): return False
    # 
    #     return self.thisptr == other.thisptr

cdef public class SeatAllotmentStrategy[object c_PySeatAllotmentStrategy, type c_PySeatAllotmentStrategy_t]:
    cdef cpp_PySeatAllotmentStrategy thisptr

    def __cinit__(self):
        self.thisptr.setInstance(self)

    def allot(self, available_seat_numbers):
        self.thisptr.allot(available_seat_numbers)

cdef PySeatAllotmentStrategy_allot(SeatAllotmentStrategy obj, vector[string] available_seat_numbers):
    obj.allot(available_seat_numbers)