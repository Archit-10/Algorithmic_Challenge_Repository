#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> v(n);
        vector<int> indegree(n, 0);
        for (auto &e : edges)
        {
            indegree[e[0]]++, indegree[e[1]]++;
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] >= 2)
                continue;
            vis[i] = true;
            q.push(i);
        }

        vector<int> result;
        while (!q.empty())
        {
            int size = q.size();
            result.clear();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                for (auto &next : v[curr])
                {
                    if (vis[next])
                        continue;
                    if ((--indegree[next]) == 1)
                    {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return result;
    }
};