#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n > 0 && !n & (n - 1))
            return true;
        return false;
    }
};