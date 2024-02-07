#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool static cmp(pair<char, int> &a, pair<char, int> &b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s)
    {
        unordered_map<char, int> umap;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            umap[s[i]]++;
        }
        vector<pair<char, int>> v;
        for (auto x : umap)
        {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), cmp);
        string ans;
        for (auto x : v)
        {
            for (int i = 0; i < x.second; i++)
            {
                ans += x.first;
            }
        }
        return ans;
    }
};