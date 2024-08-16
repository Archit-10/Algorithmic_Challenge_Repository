#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {

        int smallest = arrays[0][0];
        int largest = arrays[0].back();
        int maxi = 0;

        for (int i = 1; i < arrays.size(); i++)
        {
            maxi = max(maxi, abs(arrays[i].back() - smallest));
            maxi = max(maxi, abs(largest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            largest = max(largest, arrays[i].back());
        }

        return maxi;
    }
};