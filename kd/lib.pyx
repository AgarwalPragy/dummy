# distutils: language=c++
# cython: language_level=3

cdef extern from "class.h":
    cdef cppclass cpp_BaseClass "BaseClass":
        void foo()
        void bar()

    cdef cppclass cpp_PyClass "PyClass"(cpp_BaseClass):
        void setInstance(BaseClass)

    cdef cppclass cpp_CppClass "CppClass"(cpp_BaseClass):
        pass

cdef class CppClass:
    cdef cpp_CppClass thisptr

    def bar(self):
        self.thisptr.bar()

    def foo(self):
        self.thisptr.foo()

cdef public class BaseClass[object py_BaseClass, type py_BaseClass_t]:
    cdef cpp_PyClass thisptr

    def __cinit__(self):
        self.thisptr.setInstance(self)

    def bar(self):
        self.thisptr.bar()

    def foo(self):
        raise NotImplementedError

cdef public py_BaseClass_foo(BaseClass obj):
    obj.foo()
