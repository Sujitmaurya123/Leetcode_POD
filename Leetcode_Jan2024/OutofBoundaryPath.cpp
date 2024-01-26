/*
576. Out of Boundary Paths

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.



Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12


Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

*/
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
using int2 = pair<int, int>;
vector<int2> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int mod = 1e9 + 7;
class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int Row, int Column)
    {
        int dp[2][51][51];
        memset(dp, 0, sizeof(dp));
        for (int k = 1; k <= maxMove; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    long long ans = 0;
                    for (auto [a, b] : moves)
                    {
                        int r = i + a, c = j + b;
                        if (r < 0 || r >= m || c < 0 || c >= n)
                            ans++;
                        else
                            ans += dp[(k - 1) & 1][r][c];
                    }
                    dp[k & 1][i][j] = ans % mod;
                }
            }
        }
        return dp[maxMove & 1][Row][Column];
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();