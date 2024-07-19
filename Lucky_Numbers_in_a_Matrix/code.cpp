#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            int t = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] < t)
                    t = matrix[i][j];
            }
            umap[t]++;
        }

        for (int j = 0; j < m; j++)
        {
            int t = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] > t)
                    t = matrix[i][j];
            }
            umap[t]++;
        }

        for (auto it : umap)
        {
            if (it.second > 1)
                v.push_back(it.first);
        }
        return v;
    }
};