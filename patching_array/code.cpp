#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {

        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        long long count = 0, sum = 0, i = 0;
        while (sum < n)
        {
            if (i < nums.size() && nums[i] <= (sum + 1))
            {
                sum += nums[i++];
            }
            else
            {
                count++;
                sum += (sum + 1);
            }
        }
        return count;
    }
};