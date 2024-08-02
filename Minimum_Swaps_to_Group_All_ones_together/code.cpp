#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int wlen = 0;
        for (auto num : nums)
        {
            wlen += num;
        }

        int currzeroes = 0;
        for (int i = 0; i < wlen; i++)
        {
            if (nums[i] == 0)
                currzeroes++;
        }

        int minzeroes = currzeroes;

        int n = nums.size();
        int start = 0;
        int end = wlen - 1;

        while (start < n)
        {
            if (nums[start] == 0)
                currzeroes--;
            start++;
            end++;
            if (nums[end % n] == 0)
                currzeroes++;
            minzeroes = min(currzeroes, minzeroes);
        }

        return minzeroes;
    }
};