#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    vector<vector<int>> Graph(n + 1, vector<int>());
    for (const vector<int>& EdgeInfo : edge)
    {
        Graph[EdgeInfo[0]].push_back(EdgeInfo[1]);
        Graph[EdgeInfo[1]].push_back(EdgeInfo[0]);
    }

    vector<int> Distances(n + 1, 0);
    vector<bool> IsVisited(n + 1, false);
    int MaxDistance = 0;

    queue<int> BFS_Q;
    BFS_Q.push(1);
    IsVisited[1] = true;
    while (!BFS_Q.empty())
    {
        int CurNode = BFS_Q.front();
        BFS_Q.pop();

        int CurDistance = Distances[CurNode] + 1;
        for (int NextNode : Graph[CurNode])
        {
            if(IsVisited[NextNode] == false)
            {
                Distances[NextNode] = CurDistance;
                if (Distances[NextNode] > MaxDistance)
                {
                    MaxDistance = max(MaxDistance, CurDistance);
                }

                IsVisited[NextNode] = true;
                BFS_Q.push(NextNode);
            }
        }
    }

    int answer = 0;
    for (int Dist : Distances)
    {   
        if (Dist == MaxDistance)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    int res = solution(6, { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} });
}