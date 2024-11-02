#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        stringstream ss(sentence);
        vector<string> v;
        string word;

        while (ss >> word)
        {
            v.push_back(word);
        }

        for (size_t i = 0; i < v.size(); i++)
        {
            string currentword = v[i];
            string nextword = v[(i + 1) % v.size()];

            if (currentword.back() != nextword.front())
                return false;
        }
        return true;
    }
};