#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] < b[0])
            return true;
        if (a[0] == b[0])
            return a[1] > b[1];
        return false;
    }

    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (auto x : nums)
        {
            umap[x]++;
        }

        vector<vector<int>> v;

        for (auto x : umap)
        {
            v.push_back({x.second, x.first});
        }

        sort(v.begin(), v.end(), cmp);
        vector<int> ans;

        for (auto a : v)
        {
            int x = a[0];
            while (x--)
                ans.push_back(a[1]);
        }

        return ans;
    }
};