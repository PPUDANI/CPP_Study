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


private:
	string Name;
	int Age;
};

int main()
{
	Person Person1("Donspike", 44);
	Person Person2("Frank", 32);
	Person1 = std::move(Person2);

}