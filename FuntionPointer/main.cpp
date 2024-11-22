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
	// �ܼ��� �Լ��� ����Ű�� ������.
	// �Լ��� �޸� �ּҸ� �����ϰ� �̸� ȣ���� �� ����.
	// ���� �Լ��� ���� �Լ��� ����ų �� ����.
	int (*GetTwo_ptr)() = GetTwo;
	void (*PrintHello_ptr)() = PrintHello;

	bool (*GetT_ptr)() = GetTrue;
	bool (*GetF_ptr)() = GetFalse;

	// ���� ������ ����
	bool GetT_Res = GetT_ptr(); // true
	GetT_ptr = GetF_ptr;
	bool GetT_Res2 = GetT_ptr(); // false


	// ��� �����͵� ���� (������ ���� �Ұ�)
	bool (* const const_GetF_ptr)() = GetFalse;

	int (*Adder_ptr)(int, int) = Adder;
	int (&Adder_ref)(int, int) = Adder;
	int Adder_res1 = Adder_ptr(3, 4);
	int Adder_res2 = Adder_ref(3, 4);

	// ���ٵ� ����.
	void (*No_Capture_Ramda)() = []()
		{
			std::cout << "no capture" << std::endl;
		};

	// ��� ���� �Լ� �����ʹ� ĸó[&] �� ����� �� ����
	void (*Capture_Ramda)() = [/*&*/]()
		{
			std::cout << "capture" << std::endl;
		};

	// std::functional : �Լ� �����͸� ���� �� �ִ� Ŭ����.
	// ����, �Լ� ������, �Լ� ��ü, ��� �Լ� ���� �������� ���� �� �ֵ��� ���۵Ǿ�
	// �Լ� �����ͺ��� �ణ�� ������尡 ����.
	// std::function < ��ȯŸ��(����) >
	std::function<int(std::vector<int>&)> Sum_Ptr = Sum;
	using MyFunc = std::function<int(std::vector<int>&)>;

	MyFunc Sum_ptr = nullptr;
	Sum_ptr = Sum;

	using void_ramda = std::function<void()>;

	// functional�� ĸó ����� ����.
	int RamdaInt = 3;
	void_ramda Ramdafunc = [&]()
		{
			RamdaInt = 4;
		};

	Ramdafunc();

}
