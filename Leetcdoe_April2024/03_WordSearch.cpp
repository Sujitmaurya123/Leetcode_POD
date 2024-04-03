/*
79 Word Search
Question Link ->
https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, int i, int j, int idx, vector<vector<bool>> &vis, string &word)
    {
        if (idx == word.size() - 1)
            return true;
        vis[i][j] = true;
        int r = board.size(), c = board[0].size();
        if (i - 1 >= 0 && !vis[i - 1][j] && board[i - 1][j] == word[idx + 1] && dfs(board, i - 1, j, idx + 1, vis, word))
        {
            return true;
        }

        if (i + 1 <= r - 1 && !vis[i + 1][j] && board[i + 1][j] == word[idx + 1] && dfs(board, i + 1, j, idx + 1, vis, word))
        {
            return true;
        }
        if (j - 1 >= 0 && !vis[i][j - 1] && board[i][j - 1] == word[idx + 1] && dfs(board, i, j - 1, idx + 1, vis, word))
        {
            return true;
        }
        if (j + 1 <= c - 1 && !vis[i][j + 1] && board[i][j + 1] == word[idx + 1] && dfs(board, i, j + 1, idx + 1, vis, word))
        {
            return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int r = board.size(), c = board[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, vis, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};