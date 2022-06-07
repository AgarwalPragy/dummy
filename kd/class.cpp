#include "class.h"

#include "lib.h"

void PyClass::foo()
{
	printf("PyClass::foo()\n");
	PyBaseClass_foo(_pyInstance);
}