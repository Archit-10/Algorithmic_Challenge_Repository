#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int checkRecord(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (n == 1)
        {
            return 3;
        }
        else
        {
            long long int mod = 1e9 + 7;
            cout << mod << endl;
            long long int al = 1,
                          all = 0,
                          anl = 3,
                          nal = 1,
                          nall = 1,
                          nap = 2;
            long long int ans = 0;
            ans = al + all + anl + nal + nall + nap;
            long long int t1, t2, t3, t4, t5, t6;
            while (n > 2)
            {
                t1 = anl % mod;
                t2 = al % mod;
                t3 = (al + all + anl + nal + nall + nap) % mod;
                t4 = nap % mod;
                t5 = nal % mod;
                t6 = (nap + nal + nall) % mod;
                ans = (t1 + t2 + t3 + t4 + t5 + t6) % mod;
                al = t1;
                all = t2;
                anl = t3;
                nal = t4;
                nall = t5;
                nap = t6;
                n--;
            }
            return ans;
        }
    }
};