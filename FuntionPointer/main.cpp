#include <iostream>

#include <functional>
#include <vector>

bool GetTrue()
{
	return 1;
}

bool GetFalse()
{
	return 1;
}

int Adder(int _Left, int _Right)
{
	return _Left + _Right;
}

int Sum(std::vector<int>& _vec)
{
	int Ansewer = 0;
	for (const int i : _vec)
	{
		Ansewer += i;
	}
	return Ansewer;
}

int main()
{
	// 단순히 함수를 가라키는 포인터.
	// 함수의 메모리 주소를 저장하고 이를 호출할 수 있음.
	// 정적 함수나 전역 함수만 가리킬 수 있음.
	bool (*GetT_ptr)() = GetTrue;
	bool (*GetF_ptr)() = GetFalse;

	// 대입 연산자 가능
	GetT_ptr = GetF_ptr;
	bool (* const const_GetF_ptr)() = GetFalse;

	// 상수 포인터로 수정 불가
	// const_GetF_ptr = GetF_ptr;
	int (*Adder_ptr)(int, int) = Adder;
	int res = Adder_ptr(3, 4);


	void (*Ramda)() = []()
		{
			std::cout << "no capture" << std::endl;
		};

	// 함수 포인터는 캡처[&] 를 사용할 수 없음
	//void (*Ramda)() = [&]()
	//	{
	//		std::cout << "no capture" << std::endl;
	//	};


	// std::functional
	// 함수 포인터보다 약간의 오버헤드가 생김.
	// 람다, 함수 포인터, 함수 객체, 멤버 함수 등을 받을 수 있어 고무적임.
	std::function<int(std::vector<int>&)> Sum_Ptr = Sum;
	using MyFunc = std::function<int(std::vector<int>&)>;

	MyFunc Sum_ptr = nullptr;
	Sum_ptr = Sum;

	using void_ramda = std::function<void()>;

	// functional은 캡처 사용이 가능.
	int RamdaInt = 3;
	void_ramda Ramdafunc = [&]()
		{
			RamdaInt = 4;
		};

	Ramdafunc();

}
