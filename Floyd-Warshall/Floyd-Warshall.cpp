#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{

    vector<vector<int>> Graph(n + 1, vector<int>(n + 1, 0));
    
    for (vector<int> Res : results)
    {
        int Winner = Res[0];
        int Loser = Res[1];
        Graph[Winner][Loser] = 1;
        Graph[Loser][Winner] = -1;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; i <= n; ++j)
            {
                if (Graph[i][k] == 1 && Graph[k][j] == 1)
                {
                    Graph[i][j] = 1;
                    Graph[j][i] = -1;
                }
            }
        }
    }


    int answer = 0;

    // 각 선수에 대해, 다른 모든 선수들과의 승패 관계가 확실한지 확인
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j && graph[i][j] != 0) {
                count++; // i와 j의 승패가 확실하면 count 증가
            }
        }
        if (count == n - 1) { // n - 1개의 선수와 승패 관계가 확실하면 순위를 알 수 있다
            answer++;
        }
    }

    return answer;
    return answer;
}




int main()
{
    solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} });
}