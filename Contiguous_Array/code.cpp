#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        int cnt = 0;
        umap[0] = -1;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                cnt++;
            else
                cnt--;
            if (umap.find(cnt) != umap.end())
            {
                maxi = max(maxi, i - umap[cnt]);
            }
            else
            {
                umap[cnt] = i;
            }
        }
        return maxi;
    }
};