#include <iostream>
// #define�� '��ũ��'��� ��.
// '�ؽ�Ʈ'�� ���ľ ���� �� ����.
// �Ʒ��� ���� ���ľ ���� �����ʿ� �ؽ�Ʈ�� ���´�.

#define VALUE_A 100
#define FUNC1 void Func1(){ std::cout << "VALUE_A: " << VALUE_A << std::endl; }



// ���ٷθ� �����?
// '\'�� ����ؼ� �ٹٲ޵� ����.
#define VALUE_B 1000\
0\
0


// �̷��� �ᵵ �ؽ�Ʈ �����̶� IntelliSense�� ���� �ȶ��
#define XFUN2 std::cout << "VALUE_B: " << VALUE_B << std::endl; }

void Func2()
{
	XFUN2





// FUNC1 ��ũ�η� Func1() ����
FUNC1

int main()
{
	// FUNC1, FUNC2 ��ũ�ΰ� �� �۵��ϴ��� Ȯ��.
	Func1();
	Func2();

	// ANSI C���� ���ϰ� �����ϴ� Include�� �ʿ���� ���� ��ũ��.
	std::cout << "Date: " << __DATE__ << std::endl;
	std::cout << "Time: " << __TIME__ << std::endl;
	std::cout << "Line: " << __LINE__ << std::endl;
	std::cout << "File: " << __FILE__ << std::endl;
}