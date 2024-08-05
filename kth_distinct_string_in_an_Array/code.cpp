#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> umap;
        int cnt = 0;
        string ans;
        for (auto str : arr)
        {
            umap[str]++;
        }

        for (auto it : umap)
        {
            if (it.second == 1)
            {
                cnt++;
            }
            if (cnt == k)
            {
                ans = it.first;
                break;
            }
        }

        return ans;
    }
};