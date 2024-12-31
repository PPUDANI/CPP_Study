#pragma once
#include <iostream>

// noexcept는 해당 함수에서 예외를 던지지 않는다는 것을 명시하는 키워드임.
// 만약 이게 없다면 컴파일러의 최적화중 문제가 일어날 수 있기 때문에 이동 생성자를 호출하지 않고
// 복사가 일어날 수가 있음.
// 이를 명시해줌으로써 컴파일러가 편하게 최적화를 할 수 있음.
class DefaultClass
{
public:

    // Constructor.
    // explicit이 붙는 이유는 암시적 형변환이 일어나지 않게 방지해주는 키워드.
    explicit DefaultClass()
    {
    }

    // Destructor.
    // 파생 클래스가 있다면 virtual 붙이기.
    ~DefaultClass() noexcept
    {
        std::cout << "소멸자 호출" << std::endl;
    }

    // Copy constructor. 복사 생성자
    // 복사 생성자는 const reference를 인자로 받으며 L-value 혹은 R-value를 받을 수 있음.
    DefaultClass(const DefaultClass& other)
    {
        std::cout << "복사 생성자 호출" << std::endl;
    }

    // Move constructor. 이동 생성자
    // 이동 생성자는 &&로 R-value만 받음. 내부에서 move가 필요한 객체라면 move하고, 기본 자료형이라면 복사.
    DefaultClass(DefaultClass&& other) noexcept
    {
        std::cout << "이동 생성자 호출" << std::endl;
    }

    // Move assignment operator. 이동 연산자
    DefaultClass& operator=(DefaultClass&& other) noexcept
    {
        std::cout << "이동 연산자 호출"<< std::endl;

        if (this != &other)
        {

        }
        return *this;
    }

    // Copy assignment operator.
    DefaultClass& operator=(const DefaultClass& other)
    {
        std::cout << "복사 연산자 호출" << std::endl;

        if (this != &other)
        {

        }
        return *this;
    }

private:

};
