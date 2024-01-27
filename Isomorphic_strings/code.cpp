#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        if (m != n)
            return false;

        char m1[256] = {0};
        char m2[256] = {0};

        for (int i = 0; i < n; i++)
        {
            if (!m1[s[i]] && !m2[t[i]])
            {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if (m1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};