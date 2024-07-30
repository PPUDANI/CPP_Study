#include "B.h"
#include "A.h"

B::B()
{
	AObj = new A();
}

B::~B()
{
	delete AObj;
}

void B::Func()
{
	AObj->Func();
}