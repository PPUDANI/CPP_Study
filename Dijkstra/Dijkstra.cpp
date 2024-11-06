#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999

int solution(int N, vector<vector<int> > road, int K)
{
    vector<vector<pair<int, int>>> Graph(N + 1);
    for (vector<int> Edge : road)
    {
        int From = Edge[0];
        int To = Edge[1];
        int Dist = Edge[2];

        Graph[From].push_back({ Dist, To });
        Graph[To].push_back({ Dist, From });
    }

    vector<int> DistToNodes(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Dijkstra_PQ;

    Dijkstra_PQ.push({ 0, 1 });

    while (!Dijkstra_PQ.empty())
    {
        int CurNode = Dijkstra_PQ.top().second;
        int CurDist = Dijkstra_PQ.top().first;
        Dijkstra_PQ.pop();

        if (DistToNodes[CurNode] <= CurDist)
        {
            continue;
        }

        for (auto Edge : Graph[CurNode])
        {
            int NextNode = Edge.second;
            int NewDist = Edge.first + CurDist;

            if (DistToNodes[NextNode] > NewDist)
            {
                DistToNodes[NextNode] = NewDist;
                Dijkstra_PQ.push({ NewDist, NextNode });
            }
        }
    }

    int answer = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (K >= DistToNodes[i])
        {
            ++answer;
        }
    }

    return answer;
}
//class Edge {
//public:
//    int Distnation;
//    int Cost;
//
//    bool operator > (const Edge& _Value) const
//    {
//        return Cost > _Value.Cost;
//    }
//};
//
//int solution(int N, vector<vector<int>> road, int K) 
//{
//    vector<vector<Edge>> Graph(N + 1);
//
//    for (const vector<int>& RoadInfo : road)
//    {
//        Graph[RoadInfo[0]].push_back({ RoadInfo[1], RoadInfo[2] });
//        Graph[RoadInfo[1]].push_back({ RoadInfo[0], RoadInfo[2] });
//    }
//
//    vector<int> CostToNode(N + 1, INT32_MAX);
//    priority_queue<Edge, vector<Edge>, greater<Edge>> BFS_PQ;
//
//    CostToNode[1] = 0;
//    BFS_PQ.push({ 1, 0 });
//
//    while (!BFS_PQ.empty())
//    {
//        Edge CurEdge = BFS_PQ.top();
//        BFS_PQ.pop();
//
//        if (CurEdge.Cost > CostToNode[CurEdge.Distnation])
//        {
//            continue;
//        }
//
//        for (Edge EdgeInfo : Graph[CurEdge.Distnation])
//        {
//            EdgeInfo.Cost += CostToNode[CurEdge.Distnation];
//            if (EdgeInfo.Cost < CostToNode[EdgeInfo.Distnation])
//            {
//                CostToNode[EdgeInfo.Distnation] = EdgeInfo.Cost;
//                BFS_PQ.push(EdgeInfo);
//            }
//        }
//    }
//        
//    // K 이하로 배달 가능한 마을 수 카운트
//    int answer = 1;
//    for (int i = 2; i <= N; ++i) 
//    {
//        if (CostToNode[i] <= K)
//        {
//            answer++;
//        }
//    }
//
//    return answer;
//}

int main()
{
    int res = solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3);
    int res2 = solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4);
    int res3 = 0;
}   