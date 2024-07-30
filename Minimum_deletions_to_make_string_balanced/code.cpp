#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int bcnt = 0;
        int del = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'b')
                bcnt++;
            else
            {
                del = min(del + 1, bcnt);
            }
        }
        return del;
    }
};