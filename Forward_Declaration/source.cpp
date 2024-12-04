#include <iostream>
#include <vector>
using namespace std;


// 전방 선언은 Actor 클래스가 Level 클래스에 사용되지만, 
// 컴파일러가 Actor의 정의를 몰라도 되는 상황을 처리하기 위해 사용됨.
// 컴파일러가 Actor객체 크기를 몰라 메모리 할당을 못하므로 포인터로만 사용될 경우에만 가능.
class Actor;
class Level
{
public:
    // template으로 type을 받으면 런타임 때 호출될 경우 
    // template인자에 따라 함수가 생성됨.
    // 아래 문법이 가능해짐.
    template<typename ActorType>
    ActorType* CreateActor(const std::string& _Name, int _Dir)
    {
        ActorType* NewActor = new ActorType(_Name, _Dir); // NRVO
        ActorGroup.push_back(NewActor);
        return NewActor;
    }

private:
    std::vector<Actor*> ActorGroup;
};

class Actor
{
public:
    Actor(const string& _Name, int _Dir)
        :Name(_Name), Direction(_Dir)
    {

    }

private:
    string Name;
    int Direction;
};

int main()
{
    Level* NewLevel = new Level();
    Actor* Player = NewLevel->CreateActor<Actor>("Mario", 10);
}