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

    // ���ΰ��� ���� �����Ͱ� ���� �����Ѵٸ� ������ �ű� �� ������ �����ϰ� ����.


    // ���� ������ �� �� �ܼ��� ����.
    for (int loop = 0; loop < 2; ++loop)
    {
        // 2���� ���� ��ȸ
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // i�� j�� �̱�ٸ�?
                if (Graph[i][j] == 1)
                {
                    for (int k = 1; k <= n; ++k)
                    {
                        // j�� �̰�� ��� ������� i�� �̱� �� ����.
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

    // �� �ڵ�� ������ ����. �ѹ��� �����ϸ� ������.

    // �ݷ�: (1 > 2), (2 > 3), (3 > 4)

    //   1. 1�� 2�� �̱�Ƿ� (1 > 2) (1 > 3)
    //   2. 2�� 3�� �̱�Ƿ� (2 > 3) (2 > 4)
    //   3. 3�� 4�� �̱�Ƿ� (3 > 4)

    // ���⼭ 1�� 4�� �̱�ٴ� �����Ͱ� �־�� 1�� ������ Ȯ������ �� �ִµ� �ѹ� �����δ� ��� �ݿ��� �����.
    // ������ �ݺ��ؾ� �� ��Ȯ�� ���� ������ �� ����.
    // �� �� �ݺ��ϴ� ��������. �̰� �ᱹ ���� ���谡 ������ �� ������ �� ���� ���� ����.
}


// �÷��̵� - �ͼ� �˰����� �������.
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
                // �������� k�� ������ ��� i j �� �����Ͽ� i�� j�� �̱�ٴ� ������ �߰�����.
                // n * n�� 2���� ���͸� n��ŭ �ݺ��ϱ� ������ ���ذ� �� �� ������ ���� ���� ������ ���� ��Ȯ�� ����� ��.
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