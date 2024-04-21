#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> adj[n];
        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while (!q.empty())
        {
            int tp = q.front();
            q.pop();
            for (auto x : adj[tp])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return vis[destination];
    }
};