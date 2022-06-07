#include <stdio.h>

#include "class.h"

int main()
{
	CppClass c;
	BaseClass &base = c;

	base.foo();

	return 0;
}