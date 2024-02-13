#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string rev(string s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
        return s;
    }

    string firstPalindrome(vector<string> &words)
    {
        string ans = "";
        for (auto word : words)
        {
            if (word == rev(word))
            {
                ans = word;
                break;
            }
        }
        return ans;
    }
};