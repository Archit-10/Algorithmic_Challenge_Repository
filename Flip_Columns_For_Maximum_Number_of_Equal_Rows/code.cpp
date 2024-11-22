#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        int ans = 0;
        unordered_map<string, int> um;
        for (int row = 0; row < n; row++)
        {

            string bin = "", inv_bin = "";
            for (auto val : matrix[row])
            {
                bin += ((val == 0) ? '0' : '1');
                inv_bin += ((val == 0) ? '1' : '0');
            }

            um[bin]++;
            um[inv_bin]++;

            ans = max({ans, um[bin], um[inv_bin]});
        }

        return ans;
    }
};