#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (auto x : nums)
        {
            umap[x]++;
        }
        for (auto i : umap)
        {
            if (i.second > 1)
                return i.first;
        }
        return -1;
    }
};