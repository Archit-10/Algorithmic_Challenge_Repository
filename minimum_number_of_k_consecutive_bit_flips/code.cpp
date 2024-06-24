#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size(), flipped = 0, res = 0;
        vector<int> fp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (i >= k)
                flipped ^= fp[i - k];
            if (flipped == nums[i])
            {
                if (i + k > n)
                    return -1;
                fp[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};