#include<vector>
#include<iostream>
using namespace std;

vector<int> Parents;

int GetParent(int _Node)
{
    if (_Node == Parents[_Node])
    {
        return _Node;
    }

    return Parents[_Node] = GetParent(Parents[_Node]);
}

void UnionParent(int _Left, int _Right)
{
    int _LeftParent = GetParent(_Left);
    int _RightParent = GetParent(_Right);

    if (_LeftParent < _RightParent)
    {
        Parents[_RightParent] = _LeftParent;
    }
    else
    {
        Parents[_LeftParent] = _RightParent;
    }
}

bool IsUnion(int _Left, int _Right)
{
    int _LeftParent = GetParent(_Left);
    int _RightParent = GetParent(_Right);

    if (_LeftParent == _RightParent)
    {
        return true;
    }

    return false;
}

int main()
{
    int NumOfNode;
    int NumOfTravel;

    cin >> NumOfNode >> NumOfTravel;
    Parents.assign(NumOfNode, 0);
    for (int i = 0; i < NumOfNode; ++i)
    {
        Parents[i] = i;
    }

    for (int i = 0; i < NumOfNode; ++i)
    {
        for (int j = 0; j < NumOfNode; ++j)
        {
            bool IsConnected;
            cin >> IsConnected;

            if (IsConnected == true)
            {
                UnionParent(i, j);
            }
        }
    }

    vector<int> Travels(NumOfTravel);
    for (int i = 0; i < NumOfTravel; ++i)
    {
        cin >> Travels[i];
        --Travels[i];
    }

    bool IsTravelable = true;
    for (int i = 0; i < NumOfTravel - 1; ++i)
    {
        if (IsUnion(Travels[i], Travels[i + 1]) == false)
        {
            IsTravelable = false;
            break;
        }
    }

    if (IsTravelable)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}