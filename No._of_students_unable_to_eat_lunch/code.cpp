#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int cnt = 0, i = 0;

        queue<int> q;
        for (auto s : students)
            q.push(s);

        while (cnt < q.size() && i < sandwiches.size())
        {
            if (sandwiches[i] == q.front())
            {
                q.pop();
                i++;
                cnt = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }
        return q.size();
    }
};