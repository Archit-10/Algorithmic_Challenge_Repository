#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> v;
    void gen(int i, int n)
    {

        if (i > n)
        {
            return;
        }

        int cur = i;
        v.push_back(cur);
        for (int i = 0; i <= 9; i++)
        {
            string tmp = to_string(cur) + to_string(i);
            gen(stoi(tmp), n);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        for (int i = 1; i <= 9; i++)
        {
            gen(i, n);
        }

        return v;
    }
};