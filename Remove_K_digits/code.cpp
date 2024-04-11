#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();

        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            int j = num[i] - '0';
            while (k > 0 && !st.empty() && (st.top() - '0') > j)
            {
                k--;
                st.pop();
            }

            st.push(num[i]);
        }

        while (k--)
            st.pop();

        string s = "";
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());

        int i = 0;
        for (; i < s.length(); i++)
        {
            if (s[i] != '0')
                break;
        }
        if (s.substr(i) == "")
            return "0";
        else
            return s.substr(i);
    }
};