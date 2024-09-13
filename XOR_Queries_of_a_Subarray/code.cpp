#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        int m = queries.size();

        for (int i = 1; i < n; ++i)
        {
            arr[i] ^= arr[i - 1];
        }

        vector<int> v;
        v.reserve(m);

        for (const auto &q : queries)
        {
            int start = q[0], end = q[1];
            v.push_back(start > 0 ? arr[end] ^ arr[start - 1] : arr[end]);
        }

        return v;
    }
};