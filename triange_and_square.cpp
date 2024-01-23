#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSquare(int B)
    {
        return (((B / 2) - 1) * (B / 2)) / 2;
    }
};