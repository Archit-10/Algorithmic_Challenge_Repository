#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> umap1;
        unordered_map<string, int> umap2;
        vector<string> v;

        stringstream ss1(s1);

        stringstream ss2(s2);

        string word;

        while (ss1 >> word)
        {
            umap1[word]++;
        }

        while (ss2 >> word)
        {
            umap2[word]++;
        }

        for (auto it : umap1)
        {
            if (it.second == 1 && umap2.find(it.first) == umap2.end())
            {
                v.push_back(it.first);
            }
        }

        for (auto it : umap2)
        {
            if (it.second == 1 && umap1.find(it.first) == umap1.end())
            {
                v.push_back(it.first);
            }
        }

        return v;
    }
};