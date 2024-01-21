#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int romanToDecimal(string &str)
    {
        int n = str.size();
        map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int num = mp[str[n - 1]];

        for (int i = n - 1; i >= 0; i--)
        {
            if (mp[str[i - 1]] < mp[str[i]])
            {
                num -= mp[str[i - 1]];
            }
            else
            {
                num += mp[str[i - 1]];
            }
        }

        return num;
    }
};