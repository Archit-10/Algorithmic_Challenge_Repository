#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {

        vector<string> ans;

        unordered_map<int, string> umap;

        for (int i = 0; i < heights.size(); i++)
        {
            umap[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end(), greater<int>());

        for (int i = 0; i < heights.size(); i++)
        {
            ans.push_back(umap[heights[i]]);
        }
        return ans;
    }
};