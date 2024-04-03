#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<bool>> vis;
    bool findWord(vector<vector<char>> &b, int i, int j, string &word, int idx)
    {
        if (idx >= word.size())
        {
            return true;
        }
        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size())
        {
            return false;
        }
        if (vis[i][j] || word[idx] != b[i][j])
        {
            return false;
        }
        vis[i][j] = true;
        bool found = false;
        if (word[idx] == b[i][j])
        {
            found = findWord(b, i + 1, j, word, idx + 1) ||
                    findWord(b, i - 1, j, word, idx + 1) ||
                    findWord(b, i, j - 1, word, idx + 1) ||
                    findWord(b, i, j + 1, word, idx + 1);
        }
        vis[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int x = board.size(), y = board[0].size();
        vis.resize(x + 1);
        for (int i = 0; i <= x; i++)
        {
            vis[i].resize(y + 1);
            for (int j = 0; j <= y; j++)
            {
                vis[i][j] = false;
            }
        }
        for (int p = 0; p < board.size(); p++)
        {
            for (int q = 0; q < board[0].size(); q++)
            {
                if (board[p][q] == word[0])
                {

                    bool f = findWord(board, p, q, word, 0);
                    if (f)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};