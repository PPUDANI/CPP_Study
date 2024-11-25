#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:
    Person(const std::string& name) : name(name) {
        std::cout << name << " ������ ȣ��!" << std::endl;
    }

    Person(const Person& other) : name(other.name) {
        std::cout << name << " ���� ������ ȣ��!" << std::endl;
    }

    Person(Person&& other) noexcept : name(std::move(other.name)) {
        std::cout << name << " �̵� ������ ȣ��!" << std::endl;
        other.name = "IsMoved";
    }

    ~Person() {
        std::cout << name << " �Ҹ��� ȣ��!" << std::endl;
    }



    const string& GetName()
    {
        return name;
    }

private:
    std::string name;
};

// �� �Լ� ���� RVO�� ���� "Temporary" ��ü�� ȣ������ �޸𸮿� ���� ������
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
    Person Person3 = std::move(Person2); // <- move�� ����ϸ� �̵������ڰ� ȣ���.
    cout << endl;
    Person3.GetName();

    cout << "[ example4 = Person3 ]" << endl;
    Person Person4 = Person3;
    cout << endl;



    return 0;
}