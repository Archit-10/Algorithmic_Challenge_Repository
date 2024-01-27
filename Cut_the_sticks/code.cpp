#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> cutTheSticks(vector<int> arr)
{
    vector<int> v;
    sort(arr.begin(), arr.end());

    while (!arr.empty())
    {

        v.push_back(arr.size());
        int shortest = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] -= shortest;
        }
        auto it = arr.begin();
        while (it != arr.end())
        {
            if (*it <= 0)
            {
                it = arr.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    return v;
}