#include <string>
#include <vector>

using namespace std;

int solution_1(int n, vector<vector<int>> results)
{
    vector<vector<int>> Graph(n + 1, vector<int>(n + 1, 0));

    for (vector<int> Res : results)
    {
        int Winner = Res[0];
        int Loser = Res[1];
        Graph[Winner][Loser] = 1;
        Graph[Loser][Winner] = -1;
    }

    // 서로간의 승패 데이터가 전부 존재한다면 순위를 매길 수 있음을 이해하고 제작.


    // 내부 로직을 두 번 단순히 돌림.
    for (int loop = 0; loop < 2; ++loop)
    {
        // 2차원 벡터 순회
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // i가 j를 이긴다면?
                if (Graph[i][j] == 1)
                {
                    for (int k = 1; k <= n; ++k)
                    {
                        // j가 이겼던 모든 사람들은 i가 이길 수 있음.
                        if (Graph[j][k] == 1)
                        {
                            Graph[i][k] = 1;
                            Graph[k][i] = -1;
                        }
                    }
                }
            }
        }
    }

    // 이 코드는 문제가 있음. 한번만 실행하면 실패함.

    // 반례: (1 > 2), (2 > 3), (3 > 4)

    //   1. 1은 2를 이기므로 (1 > 2) (1 > 3)
    //   2. 2는 3을 이기므로 (2 > 3) (2 > 4)
    //   3. 3는 4을 이기므로 (3 > 4)

    // 여기서 1이 4를 이긴다는 데이터가 있어야 1의 순위를 확정지을 수 있는데 한번 루프로는 결과 반영이 어려움.
    // 여러번 반복해야 더 정확한 값을 도출할 수 있음.
    // 두 번 반복하니 성공했음. 이건 결국 더욱 관계가 깊으면 더 돌려야 할 수도 있을 것임.
}


// 플로이드 - 와샬 알고리즘을 사용했음.
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
            if (k == i)
            {
                continue;
            }

            for (int j = 1; j <= n; ++j)
            {
                // 경유지인 k를 지나는 모든 i j 를 도출하여 i가 j를 이긴다는 전적을 추가해줌.
                // n * n인 2차원 벡터를 n만큼 반복하기 때문에 손해가 날 수 있지만 전부 돌기 때문에 제일 정확한 방법인 셈.
                if (Graph[i][k] == 1 && Graph[k][j] == 1)
                {
                    Graph[i][j] = 1;
                    Graph[j][i] = -1;
                }
            }
        }
    }


    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        int UnableToRank = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (Graph[i][j] != 0)
            {
                ++UnableToRank;
            }
        }

        if (UnableToRank == n - 1)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    int res = solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} });
}