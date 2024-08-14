#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool ok(int mid, vector<int> &nums, int k)
    {
        int j = 1;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (j < n && (nums[j] - nums[i]) <= mid)
                j++;
            j--;
            cnt += (j - i);
        }
        return cnt >= k;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = nums[n - 1] - nums[0];
        int l = 0, r = diff;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (ok(mid, nums, k))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};