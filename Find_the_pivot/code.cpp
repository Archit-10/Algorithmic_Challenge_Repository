#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int x = 1;
        while (x <= n)
        {
            int pre = x * (x + 1) / 2;
            int post = ((n * (n + 1) / 2) - (x * (x - 1) / 2));
            if (pre == post)
                return x;
            x++;
        }

        return -1;
    }
};