#include <iostream>
#include <vector>
#include <string>
#include "../Timer/Timer.h"

using namespace std;

#define DEBUG 1 // 디버깅용 초기화 활성화

class Person
{
public:
	Person(string _Name = "nameless", int _Age = 0)
		: Name(_Name), Age(_Age)
	{
		cout << Name << ": 생성자 호출" << endl;
	}

    ~Person() noexcept
	{
		cout << Name << ": 소멸자 호출" << endl;
	}

	// 참고 : const 참조는 lvalue와 rvalue를 전부 받을 수 있음.
	Person(const Person& _other)
	{
		cout << Name << " <- " << _other.Name << ": 복사 생성자 호출" << endl;
		Name = _other.Name;
		Age = _other.Age;
	}

	// &&을 인자로 받을 때 other라는 이름을 붙였기 때문에 other는 lvalue라는 걸 알아야함.
	Person(Person&& _other) noexcept
		:Name(std::move(_other.Name)), Age(_other.Age) 
	{
#ifdef DEBUG
		_other.Name = "nameless"; // 디버깅용 초기화
#endif
		_other.Age = 0;
		cout << Name << " <- " << _other.Name << ": 이동 생성자 호출" << endl;
	}

	Person& operator= (const Person& _other)
	{
		if (this != &_other) {
			Name = _other.Name;
			Age = _other.Age;
			std::cout << Name << " <- " << _other.Name << ": 복사 대입 연산자 호출" << std::endl;
		}
		return *this;
	}

	Person& operator= (Person&& _other) noexcept
	{
		if (this != &_other) {
			Name = std::move(_other.Name);
			Age = _other.Age;
#if DEBUG
			_other.Name = "nameless"; // 디버깅용 초기화
#endif
			_other.Age = 0;
			std::cout << Name << " <- " << _other.Name << ": 이동 대입 연산자 호출" << std::endl;
		}
		return *this;
	}

private:
	string Name;
	int Age;
};

Person Foo()
{
	return Person();
}

int main()
{
	Person Person1("Donspike", 44);
	Person Person2("Frank", 32);

	std::swap(Person1, Person2); // 안에서 move 연산 실행.

	// 아래 코드를 보면 만든 임시 객체를 Person3에 이동하기위한 이동 연산자가 호출될 것 같지만
	// 실행해 보면 기본 생성자만 호출됨.
	// 이유는 컴파일러가 RVO/NRVO 최적화를 하기 때문임
	// 생성된 임시 객체가 Person3과 동일한 메모리 위치에 생성된다고 함.
	Person Person3 = Person("Alex", 26);

	// 이동 연산자가 호출되는 이유는 반환값은 전부 rvalue이기 때문임.
	Person3 = Foo();

	// 혼동이 올 수 있으니 명확한 기준을 보자면
	// 기본적인 정의는 메모리 주소가 없고 일시적으로 존재하는 값임.
	// 아래 기준으로 생각하면 이해가 빨라짐.
	// "rvalue는 이름이 없는 값"

	// 2. int a -> 이름있음.(lvalue)
	// 3. int& a -> 이름있음.(lvalue)
	// 4. int&& a -> 이름있음.(rvalue를 받을 수 있는 lvalue)
	// 5. foo() -> 이름없이 반환되는 값임(rvalue)
	// 6. static_cast<Person&&>() -> rvalue로 cast되서 반환되는 값임(rvalue)

	// 이런 변수들의 이름을 제거해주는 함수가 std::move()임.

	Person Person4("Jake", 55);
	Person Person5("karina", 100);

	// Person5의 rvalue를 만들었음.
	Person&& Person5_rvalue = std::move(Person5);
	
	// 하지만 아래 코드를 실행하면 복사 대입 연산자가 호출되는 것을 볼 수 있음.
	Person4 = Person5_rvalue;

	// std::move()는 그냥 내부적으로 static_cast<Person&&>()를 수행함.
	// 즉 static_cast<Person&&>()를 wapping 한 것 뿐인 함수임.

	// 실질적으로 이동을 시키는 것 같이 혼동을 줄 수 있는 이름이지만
	// 단순히 rvalue로 바꿔주는것 말고는 안함.
	Person Person6("James", 55);
	Person Person7("Matilda", 100);
	
	// 아래 코드를 실행하면 이동 연산자가 호출되는 것을 볼 수 있음.
	Person6 = static_cast<Person&&>(Person7);

	// >> 그럼 move 함수를 왜씀?
	// 1. static_cast보다 간편함
	// 2. 소유권 이전 의도를 명시적으로 표현할 수 있으며, move가 공통으로 자주 사용되므로 가독성을 높임.
}