#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    class cmp
    {
    public:
        bool operator()(string &a, string &b)
        {
            return a + b < b + a;
        }
    };

    string largestNumber(vector<int> &nums)
    {
        priority_queue<string, vector<string>, cmp> pq;
        for (auto val : nums)
        {
            string s = to_string(val);
            pq.push(s);
        }

        string ans;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans[0] == '0' ? "0" : ans;
    }
};