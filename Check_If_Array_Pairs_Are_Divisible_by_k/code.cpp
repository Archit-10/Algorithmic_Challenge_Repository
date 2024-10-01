#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        bool ans = true;
        int fq[k];
        memset(fq, 0, sizeof(fq));

        for (auto &x : arr)
        {
            x = ((x % k) + k) % k;
            fq[x]++;
        }

        for (int i = 0; i < k; ++i)
        {
            if (i == 0)
            {

                ans &= fq[i] & 1 ^ 1;
                continue;
            }
            int req = k - i;
            ans &= fq[req] == fq[i];
        }

        return ans;
    }
};