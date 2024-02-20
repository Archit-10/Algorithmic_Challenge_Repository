#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int nsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nsum += nums[i];
        }
        int ans = sum - nsum;
        return ans;
    }
};