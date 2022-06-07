import sys

sys.path.append("build/lib.linux-x86_64-3.10")

import lib


class PyImpl(lib.BaseClass):
    def foo(self):
        print("py foo")


print()
print("@@@@@@@@@@@@@ PyImpl")
print()
obj = PyImpl()
print("* calling obj.foo()")
obj.foo()
print()
print("* calling obj.bar()")
obj.bar()

print()
print("@@@@@@@@@@@@@ lib.CppClass")
print()
obj = lib.CppClass()
print("* calling obj.foo()")
obj.foo()
print()
print("* calling obj.bar()")
obj.bar()