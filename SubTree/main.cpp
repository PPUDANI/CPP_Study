#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

#define INF 999999

int solution(int n, vector<vector<int>> wires)
{
    vector<unordered_set<int>> Tree(n + 1, unordered_set<int>());

    for (const vector<int>& Wire : wires)
    {
        Tree[Wire[0]].insert(Wire[1]);
        Tree[Wire[1]].insert(Wire[0]);
    }

    vector<int> NumOfChildNode(n + 1, 1);
    vector<bool> CheckedNode(n + 1, false);
    CheckedNode[0] = true;

    unordered_set<int> CheckBuffer;
    for (int i = 0; i <= n; ++i)
    {
        int NumOfEdge = int(Tree[i].size());
        if (NumOfEdge == 1)
        {
            CheckedNode[i] = true;
            int NextNode = *Tree[i].begin();
            NumOfChildNode[NextNode] += NumOfChildNode[i];
            CheckBuffer.insert(*Tree[i].begin());
        }
    }

    while (true)
    {
        int CurCheck = int(CheckBuffer.size());
        vector<int> CurCheckedNode;
        for (int i = 0; i < CurCheck; ++i)
        {
            int CurNodeIndex = *CheckBuffer.begin();

            int NumOfEdge = 0;
            int NextNodeIndex = 0;
            for (int NextNode : Tree[CurNodeIndex])
            {
                if (CheckedNode[NextNode] == false)
                {
                    NextNodeIndex = NextNode;
                    ++NumOfEdge;
                }
            }

            if (NumOfEdge == 1)
            {
                CheckBuffer.erase(CurNodeIndex);
                CurCheckedNode.push_back(CurNodeIndex);
                NumOfChildNode[NextNodeIndex] += NumOfChildNode[CurNodeIndex];
                CheckBuffer.insert(NextNodeIndex);
            }
        }
        for (int NodeCheck : CurCheckedNode)
        {
            CheckedNode[NodeCheck] = true;
        }

        int CheckCount = 0;
        for (bool IsNodeCheck : CheckedNode)
        {
            if (IsNodeCheck == false)
            {
                ++CheckCount;
            }
        }

        if (CheckCount <= 2)
        {
            break;
        }
    }

    int answer = 0;
    if (CheckBuffer.size() == 2)
    {
        int FirstNode = *CheckBuffer.begin();
        int FirstNumOfChild = NumOfChildNode[FirstNode];
        CheckBuffer.erase(FirstNode);

        int SecondNode = *CheckBuffer.begin();
        int SecondNumOfChild = NumOfChildNode[SecondNode];

        answer = abs(FirstNumOfChild - SecondNumOfChild);
    }
    else if (CheckBuffer.size() == 1)
    {
        int CheckNode = *CheckBuffer.begin();
        int MaxNum = 0;
        int MaxNode = INF;
        for (int ChildNode : Tree[CheckNode])
        {
            if (MaxNum < NumOfChildNode[ChildNode])
            {
                MaxNum = NumOfChildNode[ChildNode];
                MaxNode = ChildNode;
            }
            else if (MaxNum == NumOfChildNode[ChildNode])
            {
                MaxNode = min(MaxNode, ChildNode);
            }
        }
        int FirstNumOfChild = NumOfChildNode[CheckNode];
        int SecondNumOfChild = NumOfChildNode[MaxNode];

        FirstNumOfChild -= SecondNumOfChild;
        answer = abs(FirstNumOfChild - SecondNumOfChild);
    }

    return answer;
}
int main()
{
    int res = solution(9, { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} });
    int re2 = solution(7, { {1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6 ,7}, });
    int aab = solution(4, { {1,2},{2,3},{3,4} });
}