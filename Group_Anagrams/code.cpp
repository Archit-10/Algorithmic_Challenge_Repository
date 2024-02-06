#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        for (auto str : strs)
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            umap[sorted].push_back(str);
        }
        for (auto entry : umap)
        {
            ans.push_back(entry.second);
        }
        return ans;
    }
};