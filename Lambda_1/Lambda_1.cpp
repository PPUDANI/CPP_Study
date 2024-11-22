
#include <iostream>

int main()
{
    int Val_1 = 1;
    int Val_2 = 2;

    // 1. capture에 '='을 사용하면 모든 값을 복사함.(오버헤드 주의.)
    // 반환형을 안쓰면 컴파일러가 알아서 반환형을 설정함.
    // 하지만 명시적으로 반환값을 적는게 좋음.
    auto equal_Lambda = [=]() -> int  
        {
            return Val_1 + Val_2;
        };

    // 2. 참조 캡쳐 사용하면 외부 값을 참조할 수 있게됨.
    auto Ampersand_Lambda = [&](int a) -> int
        {
            Val_1 += a;
            Val_2 += a;
        };

    
    // 3. 참조하고싶은 멤버변수를 캡쳐하면 해당 값의 메모리를 수정할 수 있음.
    auto Ref_Lambda = [&Val_1, &Val_2](int a) -> void
        {
            Val_1 += a;
            Val_2 += a;
        };
    Ref_Lambda(2); // 함수를 실행하면 외부 Val_1, Val_2 값이 바뀜.


    // 4. 부분 참조도 가능함.
    auto Part_Ref_Lambda = [=, &Val_1](int a) -> int
        {
            Val_1 = a + Val_2;
        };


    // 5. 부분 복사도 가능함.
    auto Part_Copy_Lambda = [&, Val_2](int a) -> int
        {
            Val_1 = a + Val_2;
        };
}
