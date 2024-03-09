#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int x = 0, y = 0;
        while (nums1[x] != nums2[y])
        {
            if (nums1[x] < nums2[y])
                x++;
            else
                y++;
            if (x == nums1.size() || y == nums2.size())
                return -1;
        }
        return nums1[x];
    }
};