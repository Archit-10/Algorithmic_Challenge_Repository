#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<vector<int>> x;
        int n = profits.size();
        for (int i = 0; i < n; i++)
        {
            x.push_back({capital[i], profits[i]});
        }
        sort(x.begin(), x.end());
        int i = 0;
        priority_queue<int> y;
        while (k--)
        {
            while (i < n && x[i][0] <= w)
            {
                y.push(x[i][1]);
                i++;
            }
            if (y.empty())
                break;
            w += y.top();
            y.pop();
        }
        return w;
    }
};