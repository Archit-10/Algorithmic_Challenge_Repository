#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int sum = 0;
        for (int x : nums)
        {
            int mx = 0;
            int temp = x, count = 0;
            while (temp > 0)
            {
                mx = max(mx, temp % 10);
                temp /= 10;
                count++;
            }
            temp = 1;
            for (int i = 0; i < count; i++)
            {
                sum += temp * mx;
                temp *= 10;
            }
        }
        return sum;
    }
};