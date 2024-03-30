#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ans(vector<int> nums, int k)
    {
        int n = nums.size();

        int i = 0, j = 0;
        int cnt = 0;

        map<int, int> mp;

        while (i < n)
        {
            mp[nums[i]]++;

            while (mp.size() > k)
            {
                auto it = mp.find(nums[j]);
                it->second--;

                if (it->second == 0)
                    mp.erase(it);
                j++;
            }
            cnt += (i - j + 1);
            i++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return ans(nums, k) - ans(nums, k - 1);
    }
};