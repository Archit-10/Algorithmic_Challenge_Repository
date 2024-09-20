#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string original = s;
        reverse(s.begin(), s.end());

        int len = s.size();

        for (int i = 0; i <= len - 1; i++)
        {
            if (!memcmp(original.c_str(), s.c_str() + i, len - i))
            {
                return s.substr(0, i) + original;
            }
        }

        return s + original;
    }
};