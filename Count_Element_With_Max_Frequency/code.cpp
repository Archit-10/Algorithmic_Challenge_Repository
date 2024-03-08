#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        map<char, int> mp;
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto x : mp)
        {
            maxi = max(maxi, x.second);
        }
        for (auto i : mp)
        {
            if (i.second == maxi)
                sum += i.second;
        }
        return sum;
    }
};