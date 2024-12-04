#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char lessChar(char ch)
    {
        return ch == 'a' ? 'z' : char(ch - 1);
    }
    bool canMakeSubsequence(string str1, string str2)
    {
        int i = 0, j = 0;

        while (i < str1.size() && j < str2.size())
        {
            if (str1[i] == lessChar(str2[j]) || str1[i] == str2[j])
            {
                j++;
            }
            i++;
        }

        return j == str2.size();
    }
};