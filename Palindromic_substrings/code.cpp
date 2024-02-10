#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    string t;
    int check(int l, int r)
    {
        int cnt = 0;
        while (l >= 0 and r <= t.size())
        {
            if (t[l--] == t[r++])
                cnt++;
            else
                break;
        }
        return cnt;
    }

public:
    int countSubstrings(string s)
    {
        int n = s.length(), ans = 0;
        t = s;
        for (int i = 0; i < n; i++)
        {
            ans += check(i, i);
            ans += check(i, i + 1);
        }
        return ans;
    }
};