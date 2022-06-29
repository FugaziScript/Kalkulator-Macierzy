#pragma once
#include <stdlib.h>
class Interface
{
protected:
	virtual void show() = 0;
	virtual void usun() = 0;
	virtual int size_x() = 0;
	virtual int size_y() = 0;
	virtual void size_set(int x, int y) = 0;
};

