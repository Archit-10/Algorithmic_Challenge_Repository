#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        bitset<100001> cache;
        vector<int> v;
        for (auto x : nums)
        {
            bool duplicate = cache.test(x);
            if (duplicate)
            {
                v.push_back(x);
            }
            else
            {
                cache.set(x);
            }
        }
        return v;
    }
};