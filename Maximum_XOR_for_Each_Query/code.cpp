#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> result;

        int mask = (1 << maximumBit) - 1;

        for (int x : nums)
        {
            result.push_back(mask ^ x);
            mask ^= x;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};