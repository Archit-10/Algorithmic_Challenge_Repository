#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m;
        if (n)
            m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        if (n > 0)
            for (int j = 0; j < m; ++j)
                if (matrix[0][j] == '1')
                    dp[0][j] = 1;
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == '1')
                    dp[i][j] = 1 + dp[i - 1][j];
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int h = dp[i][j];
                for (int k = j; k < m; ++k)
                {
                    h = min(h, dp[i][k]);
                    ans = max(ans, (k - j + 1) * h);
                }
            }
        return ans;
    }
};