#pragma once


//
//class Single
//{
//private:
//	static Single* Instance;
//
//public:
//	static Single* GetInstance();
//
//	int Add(int L, int R);
//};

class Single
{
private:
	int a = 3;
public:
	int GetA()
	{
		return a;
	}
};