#pragma once

#include "Python.h"

struct c_PyBaseClass;

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

class PyClass : public BaseClass
{
public:
	void setInstance(c_PyBaseClass* pyInstance)
	{
		this->_pyInstance = pyInstance;
	}

public:
	void foo() override;

	c_PyBaseClass* _pyInstance;
};