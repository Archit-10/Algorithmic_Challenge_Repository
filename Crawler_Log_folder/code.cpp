#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int cnt = 0;
        for (auto log : logs)
        {
            if (log != "../" && log != "./")
            {
                cnt++;
            }
            if (log == "../")
                cnt--;
            if (cnt < 0)
                cnt = 0;
        }
        return cnt;
    }
};