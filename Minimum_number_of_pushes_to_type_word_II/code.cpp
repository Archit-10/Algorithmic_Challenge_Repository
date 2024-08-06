#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> v(26, 0);

        for (auto c : word)
        {
            v[c - 'a']++;
        }

        sort(v.begin(), v.end(), greater<int>());

        int ans = 0;
        int multiplier = 0;

        for (int i = 0; i < 26; i++)
        {
            ans += v[i] * ((multiplier / 8) + 1);
            multiplier++;
        }

        return ans;
    }
};