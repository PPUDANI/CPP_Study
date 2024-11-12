#include <iostream>
#include <vector>
#include "../Timer/Timer.h"

class MyClass
{
public:
	MyClass(int _a, int _b, int _c, int _d, int _e)
		: a(_a), b(_b), c(_c), d(_d), e(_e)
	{

	}

	int a;
	int b;
	int c;
	int d;
	int e;
};

int main()
{
	MyClass mc1(1, 2, 3, 4, 5);
	MyClass mc2(6, 7, 8, 9, 10);
	mc1 = std::move(mc2);
	std::swap(mc1, mc2);

	std::vector<int> vec1 = { 1, 2, 3, 4 ,5 };
	std::vector<int> vec2 = { 6, 7, 8, 9, 0, 10};

	std::swap(vec1, vec2);

	int a = 0;
}