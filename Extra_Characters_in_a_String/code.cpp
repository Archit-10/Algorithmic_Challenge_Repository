#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                string sub = s.substr(j, i - j);
                if (dict.count(sub))
                {
                    dp[i] = min(dp[i], dp[j]);
                }
                else
                {
                    dp[i] = min(dp[i], dp[j] + (i - j));
                }
            }
        }

        return dp[n];
    }
};