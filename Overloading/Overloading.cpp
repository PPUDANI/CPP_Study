
#include <iostream>

// Pointer는 값을 바꿀수 있는지 없는지 구분지어야 하기 때문에 가능.
void Ptr(const int* _Val)
{
	std::cout << "Const Int Pointer Overloading!" << std::endl;
}

void Ptr(int* _Val)
{
	std::cout << "Int Pointer Overloading!" << std::endl;
}

void Val(int _Val)
{
	std::cout << "Int Overloading!" << std::endl;
}

// ERROR! -> 입력받는 _Val는 const 유무에 상관 없이 복사가 되기 때문에 두 함수를 구분할 수 없어 ERROR가 발생함
//void Val(const int _Val)
//{
//	std::cout << "Const Int Overloading!" << std::endl;
//}

int main()
{
	int A = 3;
	const int CA = 3;
	Val(A);
	Val(CA);
}

