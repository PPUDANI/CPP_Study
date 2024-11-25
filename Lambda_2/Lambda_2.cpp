
#include <iostream>

int main()
{
    int Val_1 = 1;
    int Val_2 = 2;
    int Val_3 = 3;
    int Val_4 = 4;

    // Lambda 함수는 이름 없는 함수 객체임.
    auto Lamb_1 = [&](int a)-> void
        {
            Val_1 += a;
            Val_2 += a;
        };

    // 위 람다 함수를 생성하면 컴파일러는 아래와 같은 임시 함수 객체를 생성함.
    class __lambda
    {
    public:
        inline /*constexpr */ void operator()(int a) const
        {
            Val_1 = Val_1 + a;
            Val_2 = Val_2 + a;
        }

    private:
        // [&]로 모든 변수를 참조할 것 같지만 람다 함수 내부에서 사용한 변수만 멤버변수를 생성함.
        int& Val_1; // 지역변수 캡쳐를 위해 생성된 멤버변수 1
        int& Val_2; // 지역변수 캡쳐를 위해 생성된 멤버변수 2

    public:
        __lambda(int& _Val_1, int& _Val_2)
            : Val_1{ _Val_1 }
            , Val_2{ _Val_2 }
        {}

    };

    // 함수객체 생성
    __lambda Lamb_1 = __lambda{ Val_1, Val_2 };

    // 3. mutable을 붙여주면 람다의 멤버 변수를 바꿀 수 있음.
    auto Mutable_Lambda = [=](int a) mutable
        {
            Val_1 += a;
            Val_2 += a;
        };

    // 아래를 실행하면 임시 함수 객체의 멤버변수인 Val_1, Val_2의 값이 바뀜.
    Mutable_Lambda(1); // 외부 Val_1, Val_2는 바뀌지 않음. 즉 복사된 것. (대충 왜 쓰는지 모르겠다는 말)
}

