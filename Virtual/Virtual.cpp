#include <iostream>
#include <list>
#include <string>

using namespace std;

class Object
{
public:
	Object()
	{
		cout << TypeName << " : Object 생성자 호출" << endl;
	}

	~Object()
	{
		cout << TypeName << " : Object 소멸자 호출" << endl;
	}

	void SetLocation(int _Val)
	{
		Location = _Val;
	}

protected:
	string TypeName = "Object";
	int Location = 0;
};

class Actor : public Object
{
public:
	Actor()
	{
		TypeName = "Actor";
		cout << TypeName << " : Actor 생성자 호출" << endl;
	}

	~Actor()
	{
		cout << TypeName << " : Actor 소멸자 호출" << endl;
	}

	void SetMaterial(string _MaterialName)
	{
		Material = _MaterialName;
		TypeName = _MaterialName;
	}

protected:
	string Material = "Default";
};

class Level : public Object
{

public:
	Level()
	{
		TypeName = "New Level";
		cout << TypeName << " : Level 생성자 호출" << endl;
	}

	~Level()
	{
		cout << TypeName << " : Level 소멸자 호출" << endl;
		for (auto actor : Actors)
		{
			delete actor; // 문제 발생
		}
	}
	
	Actor* CreateActor()
	{
		Actor* NewActor = new Actor();
		Actors.push_back(NewActor);
		return NewActor;
	}

protected:
	list<class Actor*> Actors;
};



int main()
{
	Level* NewLevel = new Level();

	Actor* Player = NewLevel->CreateActor();

	Player->SetMaterial("Rink");
	Player->SetLocation(3);

	Actor* Wall = NewLevel->CreateActor();
	Wall->SetMaterial("Brick");
	Wall->SetLocation(5);

	delete NewLevel;

}