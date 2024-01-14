#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxi = -1;
        int maxFreq = -1;
        map<char, int> mp;
        int i = 0;
        int n = s.length();
        for (int j = 0; j < s.size(); j++)
        {
            mp[s[j]]++;

            maxFreq = max(maxFreq, mp[s[j]]);

            if (((j - i + 1) - maxFreq) > k)
            {
                mp[s[i]]--;

                i++;
            }

            maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};