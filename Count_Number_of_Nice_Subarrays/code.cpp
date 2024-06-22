#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int func(vector<int> &nums, int k)
    {
        int l = 0, r = 0, cnt = 0, sum = 0;
        if (k < 0)
            return 0;
        while (r < nums.size())
        {

            sum += (nums[r] % 2);

            while (sum > k)
            {
                sum -= nums[l] % 2;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {

        return func(nums, k) - func(nums, k - 1);
    }
};