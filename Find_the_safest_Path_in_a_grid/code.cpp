#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> rowDir = {-1, 1, 0, 0};
    vector<int> colDir = {0, 0, -1, 1};
    bool isValid(int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() || visited[i][j])
            return false;
        return true;
    }

    bool isSafe(vector<vector<int>> &dist, int len)
    {
        int n = dist.size();
        queue<pair<int, int>> q;
        if (dist[0][0] < len)
            return false;

        q.push({0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = 1;
        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row == n - 1 and col == n - 1)
                    return true;

                for (int idx = 0; idx < 4; idx++)
                {
                    int newRow = row + rowDir[idx];
                    int newCol = col + colDir[idx];

                    if (isValid(newRow, newCol, visited))
                    {
                        if (dist[newRow][newCol] < len)
                            continue;
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int len = 0;
        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                dist[row][col] = len;

                for (int idx = 0; idx < 4; idx++)
                {
                    int newRow = row + rowDir[idx];
                    int newCol = col + colDir[idx];

                    if (isValid(newRow, newCol, visited))
                    {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            len++;
        }

        int low = 0, high = INT_MAX;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isSafe(dist, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};