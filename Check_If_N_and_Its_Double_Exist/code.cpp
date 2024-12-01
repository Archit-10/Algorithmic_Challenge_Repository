#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> s;

        for (int num : arr)
        {
            if (s.count(num * 2) || (num % 2 == 0 && s.count(num / 2)))
            {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};