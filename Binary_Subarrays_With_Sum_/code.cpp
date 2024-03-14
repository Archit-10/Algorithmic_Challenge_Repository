#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int cnt = 0;
        int sum = 0;
        int n = nums.size();
        unordered_map<int, int> umap;

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (sum == goal)
                cnt++;
            if (umap.find(sum - goal) != umap.end())
                cnt += umap[sum - goal];
            umap[sum]++;
        }

        return cnt;
    }
};