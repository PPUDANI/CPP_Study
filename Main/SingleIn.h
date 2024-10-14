#pragma once

class SingleIn
{
private:
	static SingleIn* Instance;
	SingleIn() {}
	~SingleIn()
	{
		if (Instance != nullptr)
		{
			delete Instance;
		}
	}

public:
	static SingleIn* GetInstance();

	int Add(int L, int R);
};

SingleIn* SingleIn::Instance = nullptr;

SingleIn* SingleIn::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SingleIn();
	}
	return Instance;
}

int SingleIn::Add(int L, int R)
{
	int Res = L + R;
	return Res;
}