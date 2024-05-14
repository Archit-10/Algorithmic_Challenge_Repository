#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = 1;
        int maxi = 0;
        int dX[4] = {-1, 0, 1, 0};
        int dY[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int newI = i + dX[k];
            int newJ = j + dY[k];

            maxi = max(maxi, grid[i][j] + solve(newI, newJ, grid, visited));
        }
        visited[i][j] = 0;
        return maxi;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxi = max(maxi, solve(i, j, grid, visited));
            }
        }
        return maxi;
    }
};