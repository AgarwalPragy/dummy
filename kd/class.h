#pragma once

#include "Python.h"

struct py_BaseClass;

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
	void setInstance(py_BaseClass* pyInstance)
	{
		this->_pyInstance = pyInstance;
	}

public:
	void foo() override;

	py_BaseClass* _pyInstance;
};