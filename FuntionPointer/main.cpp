#include <iostream>

#include <functional>
#include <vector>

bool GetFalse()
{
	return false;
}

bool GetTrue()
{
	return true;
}

int GetTwo()
{
	return 2;
}

void PrintHello()
{
	std::cout << "Hello" << std::endl;
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
	int (*GetTwo_ptr)() = GetTwo;
	void (*PrintHello_ptr)() = PrintHello;

	bool (*GetT_ptr)() = GetTrue;
	bool (*GetF_ptr)() = GetFalse;

	// 대입 연산자 가능
	bool GetT_Res = GetT_ptr(); // true
	GetT_ptr = GetF_ptr;
	bool GetT_Res2 = GetT_ptr(); // false


	// 상수 포인터도 가능 (포인터 수정 불가)
	bool (* const const_GetF_ptr)() = GetFalse;

	int (*Adder_ptr)(int, int) = Adder;
	int (&Adder_ref)(int, int) = Adder;
	int Adder_res1 = Adder_ptr(3, 4);
	int Adder_res2 = Adder_ref(3, 4);

	// 람다도 가능.
	void (*No_Capture_Ramda)() = []()
		{
			std::cout << "no capture" << std::endl;
		};

	// 대신 람다 함수 포인터는 캡처[&] 를 사용할 수 없음
	void (*Capture_Ramda)() = [/*&*/]()
		{
			std::cout << "capture" << std::endl;
		};

	// std::functional : 함수 포인터를 받을 수 있는 클래스.
	// 람다, 함수 포인터, 함수 객체, 멤버 함수 등을 고무적으로 받을 수 있도록 제작되어
	// 함수 포인터보다 약간의 오버헤드가 생김.
	// std::function < 반환타입(인자) >
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
