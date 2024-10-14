#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set> 
#include "../Timer/Timer.h"

using namespace std;

void a()
{
	size_t NumOfInput = 0;
	int MinOfLink = 0;
	cin >> NumOfInput >> MinOfLink;
	Timer::Getinstance()->StartTimer();
	vector<list<unordered_set<int>>> GroupList;

	for (int i = 0; i < NumOfInput; ++i)
	{
		int LeftNode, RightNode;
		cin >> LeftNode >> RightNode;

		int NumOfList = static_cast<int>(GroupList.size());
		bool NotConnected = true;

		int LeftConnectIndex = -1;
		int RightConnectIndex = -1;
		bool LeftIsConnected = false;
		bool RightIsConnected = false;

		for (int j = 0; j < NumOfList; ++j)
		{
			for (unordered_set<int>& Nodes : GroupList[j])
			{
				if (Nodes.find(LeftNode) != Nodes.end() &&
					LeftIsConnected == false)
				{
					LeftIsConnected = true;
					LeftConnectIndex = j;
				}

				if (Nodes.find(RightNode) != Nodes.end() &&
					RightIsConnected == false)
				{
					RightIsConnected = true;
					RightConnectIndex = j;
				}
			}
		}

		if ((LeftIsConnected && RightIsConnected) == true)
		{
			GroupList[LeftConnectIndex].splice(GroupList[LeftConnectIndex].end(), GroupList[RightConnectIndex]);
			NotConnected = false;
		}
		else if (LeftIsConnected == true)
		{
			GroupList[LeftConnectIndex].back().insert(RightNode);
			NotConnected = false;
		}
		else if (RightIsConnected == true)
		{
			GroupList[RightConnectIndex].back().insert(LeftNode);
			NotConnected = false;
		}
		if (NotConnected == true)
		{
			GroupList.push_back(list<unordered_set<int>>());
			GroupList.back().push_back(unordered_set<int>());
			GroupList.back().back().insert(LeftNode);
			GroupList.back().back().insert(RightNode);
		}
	}

	int Count = 0;
	for (const list<unordered_set<int>>& list : GroupList)
	{
		int GroupSize = 0;
		for (const unordered_set<int>& uset : list)
		{
			GroupSize += static_cast<int>(uset.size());
		}

		if (MinOfLink >= GroupSize)
		{
			Count += GroupSize;
		}
	}

	cout << Count;
}

#define NONE_CONNECTED -1
void b()
{
	size_t NumOfInput = 0;
	int MinOfLink = 0;
	cin >> NumOfInput >> MinOfLink;
	Timer::Getinstance()->StartTimer();
	vector<unordered_set<int>> Groups;

	for (int i = 0; i < NumOfInput; ++i)
	{
		int LeftNode, RightNode;
		cin >> LeftNode >> RightNode;

		size_t NumOfGroup = Groups.size();

		int LeftConnect = NONE_CONNECTED;
		int RightConnect = NONE_CONNECTED;
		bool LeftIsConnected = false;
		bool RighIstConnected = false;

		for (size_t j = 0; j < NumOfGroup; ++j)
		{
			if (Groups[j].find(LeftNode) != Groups[j].end() &&
				LeftIsConnected == false)
			{
				LeftIsConnected = true;
				LeftConnect = j;
				continue;
			}

			if (Groups[j].find(RightNode) != Groups[j].end() &&
				RighIstConnected == false)
			{
				RighIstConnected = true;
				RightConnect = j;
				continue;
			}
		}

		if ((LeftIsConnected && RighIstConnected) == true)
		{
			Groups[LeftConnect].insert(Groups[RightConnect].begin(), Groups[RightConnect].end());
			Groups.erase(Groups.begin() + RightConnect);
		}
		else if (LeftIsConnected == true)
		{
			Groups[LeftConnect].insert(RightNode);
		}
		else if (RighIstConnected == true)
		{
			Groups[RightConnect].insert(LeftNode);
		}
		else if ((LeftIsConnected || RighIstConnected) == false)
		{
			Groups.push_back(unordered_set<int>());
			Groups.back().insert(LeftNode);
			Groups.back().insert(RightNode);
		}
	}

	int Count = 0;
	for (const unordered_set<int>& Group : Groups)
	{
		int GroupSize = static_cast<int>(Group.size());
		if (MinOfLink >= GroupSize)
		{
			Count += GroupSize;
		}
	}

	cout << Count;
}

int main()
{
	a();
	cout << Timer::Getinstance()->TimeCheck();
	b();
	cout << Timer::Getinstance()->TimeCheck();
}