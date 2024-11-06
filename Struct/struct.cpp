#include<iostream>

struct MyStruct
{
	int a = 0;

	// class와 동일하게 내부에서 선언하면 inline 함수가 됨.
	void InlineFunc()
	{
		std::cout << "Inline" << std::endl;
	};

	// class와 동일하게 외부에서 선언하면 inline이 아님.
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
		//MS.PrivateFunc(); class의 기본 접근지정자는 private, struct의 기본 접근지정자는 public.
	}
	chiled a;
	a.func();
	a.vfunc();
}


//
// 1. struct는 기본 접근 지정자가 public이지만  class는 캡슐화를 강조하기 위해서 기본 접근 지정자가 private 입니다.
// struct는 데이터를 중심으로 간단한 구조를 구현할 때 많이 사용되고 class는 데이터와 행동(매서드)을 함깨 정의하는데 초점을 맞추고 있다.
// 하지만 접근 지정자를 직접 붙여주면 class와 동일한 방식으로 사용할 수 있습니다.
//