#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int sumTotal = 0;

        for (int num : nums)
        {
            sumTotal |= num;
        }
        return sumTotal << (nums.size() - 1);
    }
};