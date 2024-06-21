#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int i = 0, j = 0, cv = 0, mv = 0, ret = 0;
        minutes -= 1;

        while (j < grumpy.size())
        {

            if (grumpy[j] == 0)
                ret += customers[j];
            else
                cv += customers[j];

            if (j >= minutes)
            {
                if (mv < cv)
                    mv = cv;

                if (grumpy[i] == 1)
                    cv -= customers[i];
                i++;
            }
            j++;
        }
        ret += mv;
        return ret;
    }
};