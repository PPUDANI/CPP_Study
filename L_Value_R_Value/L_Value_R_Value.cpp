// L_Value_R_Value.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

void Ref(string& str)
{

}

void Ref2(const string& str)
{

}    

int main()
{
    string str1 = "Hello World";
    int a = 3;

    Ref(str1);

    Ref2(str1);
    Ref2("Hello World");
    Ref2(str1.substr(0, 5));
}