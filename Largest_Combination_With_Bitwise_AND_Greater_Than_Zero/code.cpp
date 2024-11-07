#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestCombination(vector<int> &nums)
    {
        int bits[32] = {0};
        for (int num : nums)
        {
            int j = 0;
            while (num > 0)
            {
                bits[j++] += num & 1;
                num >>= 1;
            }
        }
        return *std::max_element(bits, bits + 32);
    }
};