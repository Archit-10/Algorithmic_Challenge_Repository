#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                sum += nums[i];
            if (nums[i] < 0)
                sum -= abs(nums[i]);
            if (sum == 0)
                cnt++;
        }
        return cnt;
    }
};