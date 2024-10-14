
#include <iostream>
#include "MyVector.h"

int main()
{
	MyVector<int> vec(5, 0);

	vec[2] = 5;
	std::cout << "[Init 5 from Index 2]" << std::endl;
	vec.PrintData();

	vec.push_back(3);
	std::cout << "[push_back]" << std::endl;;
	vec.PrintData();

	vec.pop_back();
	std::cout << "[pop_back]" << std::endl;;
	vec.PrintData();
	
	vec.clear();
	std::cout << "[Clear]" << std::endl;;
	vec.PrintData();

}
