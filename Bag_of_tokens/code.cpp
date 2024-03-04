#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int maxScore = 0, currScore = 0;
        while (left <= right)
        {
            if (power >= tokens[left])
            {
                currScore += 1;
                power -= tokens[left++];
            }
            else
            {
                currScore -= 1;
                power += tokens[right--];
            }
            if (currScore < 0)
                break;
            maxScore = max(currScore, maxScore);
        }
        return maxScore;
    }
};