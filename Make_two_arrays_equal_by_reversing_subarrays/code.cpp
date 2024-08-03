#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> umap;
        for (auto num : arr)
        {
            umap[num]++;
        }

        for (auto num : target)
        {
            umap[num]--;
        }

        for (auto it : umap)
        {
            if (it.second != 0)
                return false;
        }
        return true;
    }
};