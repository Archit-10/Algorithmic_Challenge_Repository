#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string num = "";
        int sum = 0;
        for (auto it : s)
        {
            num += to_string((it - 'a') + 1);
        }

        for (auto it : num)
        {
            sum += it - '0';
        }

        while (--k)
        {
            int new_sum = 0;
            while (sum > 0)
            {
                new_sum += (sum % 10);
                sum /= 10;
            }
            sum = new_sum;
        }
        return sum;
    }
};