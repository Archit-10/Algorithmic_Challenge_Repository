#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = n - 1; i >= 0; i--)
        {
            q.push(deck[i]);
            if (i == 0)
                continue;
            int k = q.front();
            q.pop();
            q.push(k);
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            ans[n - i - 1] = q.front();
            q.pop();
        }
        return ans;
    }
};