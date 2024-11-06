#include <vector>

using namespace std;

#define PUDDLE -1

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> Tiles(n, vector<int>(m, 0));

    // Create Puddle
    if (!puddles.empty())
    {
        for (vector<int> PuddleIndex : puddles)
        {
            Tiles[PuddleIndex[1] - 1][PuddleIndex[0] - 1] = PUDDLE;
        }
    }

    // Tiles[Y][0] Init
    for (int Y = 0; Y < n; ++Y)
    {
        if (Tiles[Y][0] == PUDDLE)
        {
            Tiles[Y][0] = 0;
            break;
        }

        Tiles[Y][0] = 1;
    }

    // Tiles[0][X] Init
    for (int X = 0; X < m; ++X)
    {
        if (Tiles[0][X] == PUDDLE)
        {
            Tiles[0][X] = 0;
            break;
        }

        Tiles[0][X] = 1;
    }

    // Calculating
    for (int Y = 1; Y < n; ++Y)
    {
        for (int X = 1; X < m; ++X)
        {
            if (Tiles[Y][X] == PUDDLE)
            {
                Tiles[Y][X] = 0;
                continue;
            }

            int UpTile = Tiles[Y - 1][X] % 1000000007;
            int LeftTile = Tiles[Y][X - 1] % 1000000007;
            Tiles[Y][X] = (UpTile + LeftTile) % 1000000007;
        }
    }

    return Tiles[n - 1][m - 1];
}

int main()
{
    int res = solution(10, 10, {{1, 0}, {0, 1}, { 1, 1 } });

}