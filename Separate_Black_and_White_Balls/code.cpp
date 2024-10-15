#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long cnt = 0;

        int n = s.size();

        long long ocnt = 0;

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ocnt++;

            else
                ans += ocnt;
        }

        return ans;
    }
};