#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {

        int i = 0, j, k, flag;
        vector<string> ans;
        string s = "";
        while (i < words[0].length())
        {
            flag = 0;
            for (j = 1; j < words.size(); j++)
            {
                if (count(words[j].begin(), words[j].end(), words[0][i]) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                s = words[0][i];
                ans.push_back(s);
                for (j = 1; j < words.size(); j++)
                {
                    for (k = 0; k < words[j].size(); k++)
                    {
                        if (words[0][i] == words[j][k])
                        {
                            words[j].erase(words[j].begin() + k);
                            break;
                        }
                    }
                }
                words[0].erase(words[0].begin() + i);
            }
            else if (flag == 1)
            {
                i++;
            }
        }
        return ans;
    }
};