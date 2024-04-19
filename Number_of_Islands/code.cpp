#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void find(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] == '*' || grid[i][j] == '0')
            return;

        grid[i][j] = '*';
        find(i + 1, j, grid);
        find(i - 1, j, grid);
        find(i, j + 1, grid);
        find(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1')
                {
                    cnt++;
                    find(i, j, grid);
                }

        return cnt;
    }
};