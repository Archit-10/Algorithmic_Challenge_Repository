#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkTriplet(int arr[], int n)
    {
        unordered_set<int> s;

        for (int i = 0; i < n; i++)
        {
            s.insert(arr[i] * arr[i]);
        }

        for (auto i : s)
        {
            for (auto j : s)
            {
                if (s.find(i + j) != s.end())
                {
                    return true;
                }
            }
        }
        return false;
    }
};