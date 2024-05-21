#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> v;
        int n = nums.size();
        for (int num = 0; num < (1 << n); num++)
        {
            vector<int> ans;

            for (int i = 0; i < nums.size(); i++)
            {
                if (num & (1 << i))
                {
                    ans.push_back(nums[i]);
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};