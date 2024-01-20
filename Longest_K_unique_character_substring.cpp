#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {

        map<char, int> mp;
        int maxi = -1;
        int i = 0, j = 0;
        int n = s.length();

        while (j < n)
        {

            mp[s[j]]++;

            if (mp.size() < k)
            {
                j++;
            }

            if (mp.size() == k)
            {
                maxi = max(maxi, j - i + 1);
                j++;
            }

            if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }

                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};