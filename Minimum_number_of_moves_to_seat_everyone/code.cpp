#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int ans = 0;
        priority_queue<int> seat, student;
        for (int i = 0; i < seats.size(); i++)
        {
            seat.push(seats[i]);
            student.push(students[i]);
        }
        for (int i = 0; i < seats.size(); i++)
        {
            int a = seat.top();
            int b = student.top();
            ans += abs(a - b);
            seat.pop();
            student.pop();
        }
        return ans;
    }
};