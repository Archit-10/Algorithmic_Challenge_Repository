#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<int, int> umap;

        int x = 0;

        umap[0] = 1;

        long long cnt = 0;

        for (char c : word)
        {

            x ^= 1 << (c - 'a');

            cnt += umap[x];

            for (int i = 0; i < 10; i++)
            {

                cnt += umap[x ^ (1 << i)];
            }

            umap[x]++;
        }

        return cnt;
    }
};