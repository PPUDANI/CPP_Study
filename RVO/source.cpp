#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:
    Person(const std::string& name) : name(name) {
        std::cout << name << " 생성자 호출!" << std::endl;
    }

    Person(const Person& other) : name(other.name) {
        std::cout << name << " 복사 생성자 호출!" << std::endl;
    }

    Person(Person&& other) noexcept : name(std::move(other.name)) {
        std::cout << name << " 이동 생성자 호출!" << std::endl;
        other.name = "IsMoved";
    }

    ~Person() {
        std::cout << name << " 소멸자 호출!" << std::endl;
    }



    const string& GetName()
    {
        return name;
    }

private:
    std::string name;
};

// 두 함수 전부 RVO에 의해 "Temporary" 객체가 호출자의 메모리에 직접 생성됨
Person CreateExample(const string& _Name)
{
    return Person(_Name);  
}
Person CreateExample2(const string& _Name)
{
    Person Temp = Person(_Name);
    return Temp;  
}

int main() 
{
    cout << "[ CreatePerson1 ]" << endl;
    Person Person1 = CreateExample("Vi");
    cout << endl;

    cout << "[ CreatePerson2 ]" << endl;
    Person Person2 = CreateExample2("Powder");
    cout << endl;

    cout << "[ Person3 = move(Person2) ]" << endl;
    Person Person3 = std::move(Person2); // <- move를 사용하면 이동생성자가 호출됨.
    cout << endl;
    Person3.GetName();

    cout << "[ example4 = Person3 ]" << endl;
    Person Person4 = Person3;
    cout << endl;



    return 0;
}