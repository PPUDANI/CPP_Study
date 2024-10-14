

#include <iostream>
#include "../Single/Single.h"
#include "SingleIn.h"

int main()
{
	Single a = Single();
	int res = a.GetA();
	//int Res = Single::GetInstance()->Add(3, 4);

	int res2 = SingleIn::GetInstance()->Add(3, 5);

}