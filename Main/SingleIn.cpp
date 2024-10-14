#include "SingleIn.h"
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