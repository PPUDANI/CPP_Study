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

    // �� ������ ����, �ٸ� ��� ��������� ���� ���谡 Ȯ������ Ȯ��
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j && graph[i][j] != 0) {
                count++; // i�� j�� ���а� Ȯ���ϸ� count ����
            }
        }
        if (count == n - 1) { // n - 1���� ������ ���� ���谡 Ȯ���ϸ� ������ �� �� �ִ�
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