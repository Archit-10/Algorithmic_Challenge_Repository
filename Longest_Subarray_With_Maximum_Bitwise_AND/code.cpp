#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        int ans = 1;
        int i = 0;

        while (i < nums.size())
        {
            if (nums[i] == maxi)
            {
                while (i < nums.size() && nums[i++] == maxi)
                {
                    cnt++;
                }
                ans = max(ans, cnt);
                cnt = 0;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};