#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum = 0, count = 0, minDiff = INT_MAX;
        for (long long num : nums)
        {
            sum += max(num ^ k, num);
            count += (num ^ k) > num;
            minDiff = min(minDiff, abs(num - (num ^ k)));
        }
        return sum - (count % 2 ? minDiff : 0);
    }
};