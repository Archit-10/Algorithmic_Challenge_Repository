#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        set<int> s2;
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += a[i];
        }

        for (int i = 0; i < m; i++)
        {
            s2.insert(b[i]);
            sum2 += b[i];
        }

        for (int i = 0; i < n; i++)
        {
            if ((sum2 + (2 * a[i]) - sum1) % 2 == 0 && s2.find((sum2 + (2 * a[i]) - sum1) / 2) != s2.end())
            {
                return 1;
            }
        }

        return -1;
    }
};