#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &land, int i, int j, int &x, int &y)
    {
        int n = land.size(), m = land[0].size();
        if (i >= 0 && j >= 0 && i < n && j < m && land[i][j] == 1)
        {
            land[i][j] = 0;
            x = max(x, i), y = max(y, j);
            dfs(land, i + 1, j, x, y);
            dfs(land, i - 1, j, x, y);
            dfs(land, i, j + 1, x, y);
            dfs(land, i, j - 1, x, y);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (land[i][j] == 1)
                {
                    int lx = i, ly = j, x = i, y = j;
                    dfs(land, i, j, x, y);
                    v.push_back({lx, ly, x, y});
                }
            }
        }
        return v;
    }
};