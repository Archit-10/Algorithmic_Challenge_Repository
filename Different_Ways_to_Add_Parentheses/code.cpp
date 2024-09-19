#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int generate(int x, int y, char op)
    {
        if (op == '+')
            return x + y;
        if (op == '-')
            return x - y;
        if (op == '*')
            return x * y;
        return 0;
    }

    vector<int> diffWaysToCompute(string exp)
    {
        vector<int> ans;
        bool isNumber = 1;

        for (int i = 0; i < exp.length(); i++)
        {

            if (!isdigit(exp[i]))
            {

                isNumber = 0;

                vector<int> left = diffWaysToCompute(exp.substr(0, i));

                vector<int> right = diffWaysToCompute(exp.substr(i + 1));

                for (int x : left)
                {
                    for (int y : right)
                    {
                        int val = generate(x, y, exp[i]);
                        ans.push_back(val);
                    }
                }
            }
        }

        if (isNumber == 1)
            ans.push_back(stoi(exp));
        return ans;
    }
};