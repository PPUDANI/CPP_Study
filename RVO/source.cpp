#include <iostream>
#include <string>

using namespace std;

class Example 
{
public:
    Example(const std::string& name) : name(name) {
        std::cout << name << " ������ ȣ��!" << std::endl;
    }

    Example(const Example& other) : name(other.name) {
        std::cout << name << " ���� ������ ȣ��!" << std::endl;
    }

    Example(Example&& other) noexcept : name(std::move(other.name)) {
        std::cout << name << " �̵� ������ ȣ��!" << std::endl;
    }

    ~Example() {
        std::cout << name << " �Ҹ��� ȣ��!" << std::endl;
    }

private:
    std::string name;
};

Example CreateExample() 
{
    return Example("Temporary");  // RVO�� ���� "Temporary" ��ü�� ȣ������ �޸𸮿� ���� ������
}
Example CreateExample2()
{
    Example Temp = Example("Temporary");
    return Temp;  // RVO�� ���� "Temporary" ��ü�� ȣ������ �޸𸮿� ���� ������
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