#include <iostream>
#include <vector>
using namespace std;

class Actor;
class Level
{
public:
    template<typename ActorType>
    ActorType* CreateActor(const std::string& _Name, int _Dir)
    {
        
        ActorType* NewActor = new ActorType(_Name, _Dir);
        Actors.push_back(NewActor);
        return NewActor;
        std::vector<Actor*> ActorGroup;
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