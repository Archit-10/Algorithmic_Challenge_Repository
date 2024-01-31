#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        int n = temperatures.size();
        std::vector<int> answer(n, 0);
        std::stack<int> stack;

        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int prevIndex = stack.top();
                stack.pop();
                answer[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }

        return answer;
    }
};
