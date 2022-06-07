#include "class.h"

#include "lib.h"

void PyClass::foo()
{
	printf("PyClass::foo()\n");
	py_BaseClass_foo(_pyInstance);
}