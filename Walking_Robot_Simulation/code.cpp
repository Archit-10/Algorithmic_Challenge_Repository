#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int dir = 0;
        int x = 0, y = 0;

        set<pair<int, int>> st;

        for (auto i : obstacles)
            st.insert({i[0], i[1]});

        long long maxDist = 0;
        for (int i : commands)
        {
            if (i == -2)
            {
                dir = (dir + 1) % 4;
            }
            else if (i == -1)
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                long long newX, newY;
                if (dir == 0)
                {
                    newX = x;
                    newY = y;
                    for (int j = y + 1; j <= y + i; j++)
                    {
                        if (st.count({x, j}))
                            break;
                        newY = j;
                    }
                }
                else if (dir == 1)
                {
                    newY = y;
                    newX = x;
                    for (int j = x - 1; j >= x - i; j--)
                    {
                        if (st.count({j, y}))
                            break;
                        newX = j;
                    }
                }
                else if (dir == 2)
                {
                    newX = x;
                    newY = y;
                    for (int j = y - 1; j >= y - i; j--)
                    {
                        if (st.count({x, j}))
                            break;
                        newY = j;
                    }
                }
                else
                {
                    newY = y;
                    newX = x;
                    for (int j = x + 1; j <= x + i; j++)
                    {
                        if (st.count({j, y}))
                            break;
                        newX = j;
                    }
                }

                long long dist = (newX * newX) + (newY * newY);
                if ((dist) > maxDist)
                    maxDist = dist;

                x = newX;
                y = newY;
            }
        }

        return maxDist;
    }
};