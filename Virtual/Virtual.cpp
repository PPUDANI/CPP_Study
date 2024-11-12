#include <iostream>
#include <list>
#include <string>

using namespace std;

class Object
{
public:
	Object()
	{
		cout << TypeName << " : Object ������ ȣ��" << endl;
	}

	~Object()
	{
		cout << TypeName << " : Object �Ҹ��� ȣ��" << endl;
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
		cout << TypeName << " : Actor ������ ȣ��" << endl;
	}

	~Actor()
	{
		cout << TypeName << " : Actor �Ҹ��� ȣ��" << endl;
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
		cout << TypeName << " : Level ������ ȣ��" << endl;
	}

	~Level()
	{
		cout << TypeName << " : Level �Ҹ��� ȣ��" << endl;
		for (auto actor : Actors)
		{
			delete actor; // ���� �߻�
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