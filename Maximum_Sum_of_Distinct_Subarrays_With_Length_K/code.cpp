#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> umap;
        long long maxi = 0;
        long long sum = 0;

        while (j < n)
        {

            umap[nums[j]]++;
            sum += nums[j];

            while (umap[nums[j]] > 1 || (j - i + 1 > k))
            {
                umap[nums[i]]--;
                if (umap[nums[i]] == 0)
                    umap.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            if (j - i + 1 == k && umap.size() == k)
            {
                maxi = max(maxi, sum);
            }

            j++;
        }

        return maxi;
    }
};