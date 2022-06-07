#pragma once

#include "class.h"

struct py_BaseClass;

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