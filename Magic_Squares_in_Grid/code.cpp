#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMagic(vector<vector<int>> &grid, int x, int y)
    {
        vector<int> nums(10, 0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[x + i][y + j];
                if (num < 1 || num > 9 || nums[num] != 0)
                {
                    return false;
                }
                nums[num]++;
            }
        }

        int sum1 = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        int sum2 = grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2];
        int sum3 = grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2];

        int col1 = grid[x][y] + grid[x + 1][y] + grid[x + 2][y];
        int col2 = grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1];
        int col3 = grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2];

        int diag1 = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int diag2 = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];

        return (sum1 == 15 && sum2 == 15 && sum3 == 15 &&
                col1 == 15 && col2 == 15 && col3 == 15 &&
                diag1 == 15 && diag2 == 15);
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                if (isMagic(grid, i, j))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};