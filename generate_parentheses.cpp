#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void helper(int oc, int cc, vector<string> &ans, int n, string s)
    {
        if (oc == n && cc == n)
        {
            ans.push_back(s);
            return;
        }
        if (oc < n)
        {
            helper(oc + 1, cc, ans, n, s + '(');
        }
        if (cc < oc)
        {
            helper(oc, cc + 1, ans, n, s + ')');
        }
    }
    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        int oc = 0, cc = 0;
        helper(oc, cc, ans, n, "");
        return ans;
    }
};