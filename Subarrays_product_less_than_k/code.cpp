#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k == 0)
            return 0;
        int cnt = 0;
        int n = nums.size();
        int prod = 1;
        for (int i = 0, j = 0; j < n; j++)
        {
            prod *= nums[j];
            while (i <= j && prod >= k)
            {
                prod /= nums[i++];
            }
            cnt += j - i + 1;
            cout << cnt << endl;
        }
        return cnt;
    }
};