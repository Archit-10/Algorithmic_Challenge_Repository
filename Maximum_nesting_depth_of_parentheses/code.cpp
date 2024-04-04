#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int cnt = 0;
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else if (s[i] == ')')
            {

                cnt--;
            }
        }
        return ans;
    }
};