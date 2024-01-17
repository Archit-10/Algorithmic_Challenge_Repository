#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int posOfRightMostDiffBit(int m, int n)
    {
        int num = m ^ n;
        for (int i = 0; i < 32; i++)
        {
            if (num & (1 << i))
            {
                return i + 1;
            }
        }
        return -1;
    }
};