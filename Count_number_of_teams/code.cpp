#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {

        int ans = 0;
        int n = rating.size();

        for (int i = 1; i < n - 1; i++)
        {
            int Sl = 0;
            int Sr = 0;
            int Gl = 0;
            int Gr = 0;

            for (int j = 0; j < i; j++)
            {
                if (rating[j] < rating[i])
                {
                    Sl++;
                }
                if (rating[j] > rating[i])
                {
                    Gl++;
                }
            }

            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] < rating[i])
                {
                    Sr++;
                }
                if (rating[j] > rating[i])
                {
                    Gr++;
                }
            }

            ans += (Sl * Gr) + (Gl * Sr);
        }
        return ans;
    }
};