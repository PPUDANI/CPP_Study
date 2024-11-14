#include <iostream>
#include <string>

using namespace std;

class Example 
{
public:
    Example(const std::string& name) : name(name) {
        std::cout << name << " 생성자 호출!" << std::endl;
    }

    Example(const Example& other) : name(other.name) {
        std::cout << name << " 복사 생성자 호출!" << std::endl;
    }

    Example(Example&& other) noexcept : name(std::move(other.name)) {
        std::cout << name << " 이동 생성자 호출!" << std::endl;
    }

    ~Example() {
        std::cout << name << " 소멸자 호출!" << std::endl;
    }

private:
    std::string name;
};

Example CreateExample() 
{
    return Example("Temporary");  // RVO에 의해 "Temporary" 객체가 호출자의 메모리에 직접 생성됨
}
Example CreateExample2()
{
    Example Temp = Example("Temporary");
    return Temp;  // RVO에 의해 "Temporary" 객체가 호출자의 메모리에 직접 생성됨
}

int main() 
{
    cout << "CreateExample" << endl;

    Example example = CreateExample();

    cout << "CreateExample2" << endl;
    Example example2 = CreateExample2(); 

    example = example2;

    return 0;
}