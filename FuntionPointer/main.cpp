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
	// �ܼ��� �Լ��� ����Ű�� ������.
	// �Լ��� �޸� �ּҸ� �����ϰ� �̸� ȣ���� �� ����.
	// ���� �Լ��� ���� �Լ��� ����ų �� ����.
	bool (*GetT_ptr)() = GetTrue;
	bool (*GetF_ptr)() = GetFalse;

	// ���� ������ ����
	GetT_ptr = GetF_ptr;
	bool (* const const_GetF_ptr)() = GetFalse;

	// ��� �����ͷ� ���� �Ұ�
	// const_GetF_ptr = GetF_ptr;
	int (*Adder_ptr)(int, int) = Adder;
	int res = Adder_ptr(3, 4);


	void (*Ramda)() = []()
		{
			std::cout << "no capture" << std::endl;
		};

	// �Լ� �����ʹ� ĸó[&] �� ����� �� ����
	//void (*Ramda)() = [&]()
	//	{
	//		std::cout << "no capture" << std::endl;
	//	};


	// std::functional
	// �Լ� �����ͺ��� �ణ�� ������尡 ����.
	// ����, �Լ� ������, �Լ� ��ü, ��� �Լ� ���� ���� �� �־� ������.
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
