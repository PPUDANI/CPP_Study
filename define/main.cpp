#include <iostream>
// #define은 '메크로'라고 함.
// '텍스트'에 수식어를 넣을 수 있음.
// 아래와 같이 수식어를 쓰고 오른쪽에 텍스트를 적는다.

#define VALUE_A 100
#define FUNC1 void Func1(){ std::cout << "VALUE_A: " << VALUE_A << std::endl; }



// 한줄로만 써야함?
// '\'를 사용해서 줄바꿈도 가능.
#define VALUE_B 1000\
0\
0


// 이렇게 써도 텍스트 복붙이라 IntelliSense도 오류 안띄움
#define XFUN2 std::cout << "VALUE_B: " << VALUE_B << std::endl; }

void Func2()
{
	XFUN2





// FUNC1 메크로로 Func1() 선언
FUNC1

int main()
{
	// FUNC1, FUNC2 메크로가 잘 작동하는지 확인.
	Func1();
	Func2();

	// ANSI C에서 편리하게 제공하는 Include가 필요없는 내장 메크로.
	std::cout << "Date: " << __DATE__ << std::endl;
	std::cout << "Time: " << __TIME__ << std::endl;
	std::cout << "Line: " << __LINE__ << std::endl;
	std::cout << "File: " << __FILE__ << std::endl;
}