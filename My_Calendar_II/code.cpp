#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyCalendarTwo
{
public:
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;

    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (pair<int, int> x : a)
        {
            if (start < x.second && end > x.first)
                return false;
        }
        for (pair<int, int> x : b)
        {
            if (start < x.second && end > x.first)
            {
                a.push_back({max(start, x.first), min(end, x.second)});
            }
        }
        b.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */