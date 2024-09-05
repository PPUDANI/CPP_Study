
#include <iostream>

#include "MyVector.h"


int main()
{
	MyVector<int> a(10, 5);

	a[2] = 5;

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << std::endl;
	}
}