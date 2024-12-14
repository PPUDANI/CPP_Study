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

	Person(Person& _other)
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
		cout << Name << " <- " << _other.Name << ": 이동 생성자 호출" << endl;
	}

	Person& operator= (Person& _other)
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
			std::cout << Name << " <- " << _other.Name << ": 이동 대입 연산자 호출" << std::endl;
		}
		return *this;
	}

private:
	string Name;
	int Age;
};

int main()
{


}