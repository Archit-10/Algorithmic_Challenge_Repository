#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int, int>> ans;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int i = 0; i < N; i++)
        {
            mp1[A[i]]++;
        }
        for (int i = 0; i < M; i++)
        {
            mp2[B[i]]++;
        }
        for (auto it : mp1)
        {
            int sum = X - it.first;
            if (mp2.find(sum) != mp2.end())
            {
                ans.push_back({it.first, sum});
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};