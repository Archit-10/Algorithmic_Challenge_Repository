#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        int n = s.size();

        auto isPalindrome = [](const string &str)
        {
            int left = 0, right = str.size() - 1;
            while (left < right)
            {
                if (str[left] != str[right])
                    return false;
                left++;
                right--;
            }
            return true;
        };

        function<void(int, vector<string> &)> getAllPartitions = [&](int curInd, vector<string> &curList)
        {
            if (curInd == n)
            {
                if (isPalindrome(curList.back()))
                {
                    res.push_back(curList);
                }
                return;
            }
            if (isPalindrome(curList.back()))
            {
                curList.push_back(string(1, s[curInd]));
                getAllPartitions(curInd + 1, curList);
                curList.pop_back();
            }
            curList.back().push_back(s[curInd]);
            getAllPartitions(curInd + 1, curList);
            curList.back().pop_back();
        };

        vector<string> initial = {string(1, s[0])};
        getAllPartitions(1, initial);
        return res;
    }
};