#include <iostream>
#include <vector>
using namespace std;


// ���� ������ Actor Ŭ������ Level Ŭ������ ��������, 
// �����Ϸ��� Actor�� ���Ǹ� ���� �Ǵ� ��Ȳ�� ó���ϱ� ���� ����.
// �����Ϸ��� Actor��ü ũ�⸦ ���� �޸� �Ҵ��� ���ϹǷ� �����ͷθ� ���� ��쿡�� ����.
class Actor;
class Level
{
public:
    // template���� type�� ������ ��Ÿ�� �� ȣ��� ��� 
    // template���ڿ� ���� �Լ��� ������.
    // �Ʒ� ������ ��������.
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