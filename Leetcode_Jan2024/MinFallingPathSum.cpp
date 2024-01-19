/*
931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ld = 1e9, rd = 1e9;
                int up = matrix[i][j] + dp[i - 1][j];

                if (j - 1 >= 0)
                    ld = matrix[i][j] + dp[i - 1][j - 1];
                if (j + 1 < m)
                    rd = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int mini = dp[n - 1][0];

        for (int j = 1; j < m; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};