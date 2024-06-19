#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool possible(vector<int> &v, int day, int m, int k)
    {
        int total = 0;
        int cnt = 0;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] <= day)
            {
                cnt++;
            }
            else
            {
                total += (cnt / k);
                cnt = 0;
            }
        }
        total += (cnt / k);
        return total >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        long long n = bloomDay.size();
        if (m * 1ll * k * 1ll > n)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high)
        {

            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};