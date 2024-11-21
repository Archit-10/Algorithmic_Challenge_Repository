#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n));
        int res = 0, i, j;

        for (auto w : walls)
            grid[w[0]][w[1]] = 3;
        for (auto g : guards)
            grid[g[0]][g[1]] = 2;

        for (auto g : guards)
        {
            i = g[0] + 1, j = g[1];
            while (i < m && (grid[i][j] == 0 || grid[i][j] == 1))
                grid[i++][j] = 1;

            i = g[0] - 1, j = g[1];
            while (i >= 0 && (grid[i][j] == 0 || grid[i][j] == 1))
                grid[i--][j] = 1;

            i = g[0], j = g[1] + 1;
            while (j < n && (grid[i][j] == 0 || grid[i][j] == 1))
                grid[i][j++] = 1;

            i = g[0], j = g[1] - 1;
            while (j >= 0 && (grid[i][j] == 0 || grid[i][j] == 1))
                grid[i][j--] = 1;
        }

        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (grid[a][b] == 0)
                    res++;
            }
        }
        return res;
    }
};