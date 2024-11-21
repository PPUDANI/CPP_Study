#include <iostream>


class Parent
{
public:

	// 파생 클래스는 무조건 재정의를 해야한다는 제약을 거는 것임.
	// 클래스 자신이 멤버함수를 순수 가상함수로 지정한 이상 정의 할 수 없기 때문에
	// 순수 가상함수를 선언한 클래스는 객체를 생성할 수 없음.
	virtual int Foo() = 0;
};

class Child1 : public Parent
{
	// Foo()를 재정의한 파생 클래스
	int Foo() override
	{
		std::cout << "재정의" << std::endl;
		return 0;
	}
};

class Child2 : public Parent
{
	// Foo()를 재정의 하지 않은 파생 클래스
};


int main()
{
	Child1 C1 = Child1();
	Parent* P1 = dynamic_cast<Parent*>(&C1);
	// Parent P2 = Parent(); -> ERROR! 순수가상함수를 보유한 클래스는 객체를 생성할 수 없음.
	// Child2 C2 = Child2(); -> ERROR! 순수가상함수가 있는 클래스를 상속받은 클래스는 재정의하지 않으면 ERROR가 발생함.

	P1->Foo();
}

