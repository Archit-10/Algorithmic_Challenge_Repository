#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countOfAtoms(string formula)
    {

        stack<map<string, int>> stk;
        stk.push({});
        int n = formula.size();
        for (int i = 0; i < n;)
        {
            if (formula[i] == '(')
            {
                stk.push({});
                i++;
            }
            else if (formula[i] == ')')
            {
                auto top = stk.top();
                stk.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                int multiplicity = (i > start) ? stoi(formula.substr(start, i - start)) : 1;
                for (auto &p : top)
                {
                    stk.top()[p.first] += p.second * multiplicity;
                }
            }
            else
            {
                int start = i++;
                while (i < n && islower(formula[i]))
                    i++;
                string name = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                int multiplicity = (i > start) ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[name] += multiplicity;
            }
        }
        map<string, int> &count = stk.top();
        string result;
        for (auto &p : count)
        {
            result += p.first;
            if (p.second > 1)
                result += to_string(p.second);
        }
        return result;
    }
};