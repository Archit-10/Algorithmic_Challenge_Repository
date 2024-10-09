#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open_c = 0, close_c = 0;

        for (auto c : s)
        {
            if (c == '(')
            {
                open_c++;
            }
            else if (c == ')' && open_c > 0)
            {
                open_c--;
            }
            else
            {
                close_c++;
            }
        }

        return open_c + close_c;
    }
};