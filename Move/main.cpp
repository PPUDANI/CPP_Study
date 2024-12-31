#include <iostream>
#include <vector>
#include <string>
#include "../Timer/Timer.h"

using namespace std;

#define DEBUG 1 // ������ �ʱ�ȭ Ȱ��ȭ

class Person
{
public:
	Person(string _Name = "nameless", int _Age = 0)
		: Name(_Name), Age(_Age)
	{
		cout << Name << ": ������ ȣ��" << endl;
	}

    ~Person() noexcept
	{
		cout << Name << ": �Ҹ��� ȣ��" << endl;
	}

	// ���� : const ������ lvalue�� rvalue�� ���� ���� �� ����.
	Person(const Person& _other)
	{
		cout << Name << " <- " << _other.Name << ": ���� ������ ȣ��" << endl;
		Name = _other.Name;
		Age = _other.Age;
	}

	// &&�� ���ڷ� ���� �� other��� �̸��� �ٿ��� ������ other�� lvalue��� �� �˾ƾ���.
	Person(Person&& _other) noexcept
		:Name(std::move(_other.Name)), Age(_other.Age) 
	{
#ifdef DEBUG
		_other.Name = "nameless"; // ������ �ʱ�ȭ
#endif
		_other.Age = 0;
		cout << Name << " <- " << _other.Name << ": �̵� ������ ȣ��" << endl;
	}

	Person& operator= (const Person& _other)
	{
		if (this != &_other) {
			Name = _other.Name;
			Age = _other.Age;
			std::cout << Name << " <- " << _other.Name << ": ���� ���� ������ ȣ��" << std::endl;
		}
		return *this;
	}

	Person& operator= (Person&& _other) noexcept
	{
		if (this != &_other) {
			Name = std::move(_other.Name);
			Age = _other.Age;
#if DEBUG
			_other.Name = "nameless"; // ������ �ʱ�ȭ
#endif
			_other.Age = 0;
			std::cout << Name << " <- " << _other.Name << ": �̵� ���� ������ ȣ��" << std::endl;
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

	std::swap(Person1, Person2); // �ȿ��� move ���� ����.

	// �Ʒ� �ڵ带 ���� ���� �ӽ� ��ü�� Person3�� �̵��ϱ����� �̵� �����ڰ� ȣ��� �� ������
	// ������ ���� �⺻ �����ڸ� ȣ���.
	// ������ �����Ϸ��� RVO/NRVO ����ȭ�� �ϱ� ������
	// ������ �ӽ� ��ü�� Person3�� ������ �޸� ��ġ�� �����ȴٰ� ��.
	Person Person3 = Person("Alex", 26);

	// �̵� �����ڰ� ȣ��Ǵ� ������ ��ȯ���� ���� rvalue�̱� ������.
	Person3 = Foo();

	// ȥ���� �� �� ������ ��Ȯ�� ������ ���ڸ�
	// �⺻���� ���Ǵ� �޸� �ּҰ� ���� �Ͻ������� �����ϴ� ����.
	// �Ʒ� �������� �����ϸ� ���ذ� ������.
	// "rvalue�� �̸��� ���� ��"

	// 2. int a -> �̸�����.(lvalue)
	// 3. int& a -> �̸�����.(lvalue)
	// 4. int&& a -> �̸�����.(rvalue�� ���� �� �ִ� lvalue)
	// 5. foo() -> �̸����� ��ȯ�Ǵ� ����(rvalue)
	// 6. static_cast<Person&&>() -> rvalue�� cast�Ǽ� ��ȯ�Ǵ� ����(rvalue)

	// �̷� �������� �̸��� �������ִ� �Լ��� std::move()��.

	Person Person4("Jake", 55);
	Person Person5("karina", 100);

	// Person5�� rvalue�� �������.
	Person&& Person5_rvalue = std::move(Person5);
	
	// ������ �Ʒ� �ڵ带 �����ϸ� ���� ���� �����ڰ� ȣ��Ǵ� ���� �� �� ����.
	Person4 = Person5_rvalue;

	// std::move()�� �׳� ���������� static_cast<Person&&>()�� ������.
	// �� static_cast<Person&&>()�� wapping �� �� ���� �Լ���.

	// ���������� �̵��� ��Ű�� �� ���� ȥ���� �� �� �ִ� �̸�������
	// �ܼ��� rvalue�� �ٲ��ִ°� ����� ����.
	Person Person6("James", 55);
	Person Person7("Matilda", 100);
	
	// �Ʒ� �ڵ带 �����ϸ� �̵� �����ڰ� ȣ��Ǵ� ���� �� �� ����.
	Person6 = static_cast<Person&&>(Person7);

	// >> �׷� move �Լ��� �־�?
	// 1. static_cast���� ������
	// 2. ������ ���� �ǵ��� ��������� ǥ���� �� ������, move�� �������� ���� ���ǹǷ� �������� ����.
}