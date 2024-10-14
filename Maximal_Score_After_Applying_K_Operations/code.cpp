#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        long long ans = 0;

        for (auto i : nums)
        {
            pq.push(i);
        }

        while (k--)
        {
            int b = pq.top();
            pq.pop();
            ans += b;

            int a = ceil(b / 3.0);
            pq.push(a);
        }

        return ans;
    }
};