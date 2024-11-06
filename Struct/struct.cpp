#include<iostream>

struct MyStruct
{
	int a = 0;

	// class�� �����ϰ� ���ο��� �����ϸ� inline �Լ��� ��.
	void InlineFunc()
	{
		std::cout << "Inline" << std::endl;
	};

	// class�� �����ϰ� �ܺο��� �����ϸ� inline�� �ƴ�.
	void OutlineFunc();
	inline void OutlineFunc2();
private:
	void PrivateFunc()
	{
		std::cout << "Private" << std::endl;
	}
};

void MyStruct::OutlineFunc()
{
	std::cout << "OutLine" << std::endl;
	return;
}

void MyStruct::OutlineFunc2()
{
	std::cout << "OutLine2" << std::endl;
	return;
}

struct parent
{
	int a = 0;
	void func()
	{
		std::cout << "parent" << std::endl;
	}

	virtual void vfunc()
	{
		std::cout << "parent V" << std::endl;
	}
};

struct chiled : public parent
{
	void vfunc() override
	{
		std::cout << "child V" << std::endl;
	}
};

int main()
{
	{
		MyStruct MS;
		MS.InlineFunc();
		MS.OutlineFunc();
		//MS.PrivateFunc(); class�� �⺻ ���������ڴ� private, struct�� �⺻ ���������ڴ� public.
	}
	chiled a;
	a.func();
	a.vfunc();
}


//
// 1. struct�� �⺻ ���� �����ڰ� public������  class�� ĸ��ȭ�� �����ϱ� ���ؼ� �⺻ ���� �����ڰ� private �Դϴ�.
// struct�� �����͸� �߽����� ������ ������ ������ �� ���� ���ǰ� class�� �����Ϳ� �ൿ(�ż���)�� �Ա� �����ϴµ� ������ ���߰� �ִ�.
// ������ ���� �����ڸ� ���� �ٿ��ָ� class�� ������ ������� ����� �� �ֽ��ϴ�.
//