#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> umap;
        vector<int> v;

        for (auto x : arr)
        {
            umap[x]++;
        }

        for (auto i : umap)
        {
            v.push_back(i.second);
        }
        sort(v.begin(), v.end());

        int n = v.size();
        int cnt = n;

        for (int i = 0; i < n; i++)
        {
            if (v[i] <= k)
            {
                cnt--;
                k -= v[i];
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};