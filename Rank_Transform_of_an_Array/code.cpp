#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};
        unordered_map<int, int> umap;
        vector<int> v = arr;
        sort(v.begin(), v.end());
        umap[v[0]] = 1;
        int rank = 2;

        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
                umap[v[i]] = rank++;
        }

        for (int i = 0; i < n; i++)
        {
            v[i] = umap[arr[i]];
        }
        return v;
    }
};