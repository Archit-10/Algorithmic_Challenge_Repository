#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int result = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            bool flip = (grid[i][0] == 0);
            int curr = 0;
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = (flip != grid[i][j]);
                curr = curr * 2 + grid[i][j];
            }
            result += curr;
        }
        for (int i = 1; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                cnt += !(grid[j][i]);
            if (cnt > m / 2)
                result += pow(2, n - i - 1) * (cnt - m + cnt);
        }
        return result;
    }
};