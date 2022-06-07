#pragma once

#include <stdio.h>

class BaseClass
{
public:
	virtual void foo() = 0;

	void bar()
	{
		printf("BaseClass::bar()\n");
		foo();
	}
};

class CppClass : public BaseClass
{
public:
	void foo() override
	{
		printf("CppClass::foo()\n");
	}
};
