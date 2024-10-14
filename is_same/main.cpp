#include <type_traits>
#include <iostream>
#include <stack>

int main()
{
	bool Int_Is_Int = std::is_same<int, int>::value;
	bool Int_Is_Double = std::is_same<int, double>::value;



	std::cout << "int Is Same int?  " << (Int_Is_Int == true ? "yes" : "no") << std::endl;
	std::cout << "int Is Same double?  " << (Int_Is_Double == true ? "yes" : "no") << std::endl;



	bool Stack_use_Deque = std::is_same<std::stack<int>, std::stack<int, std::deque<int>>>::value;
	std::cout << "Stack Use Deque default  " << (Stack_use_Deque == true ? "yes" : "no") << std::endl;
}