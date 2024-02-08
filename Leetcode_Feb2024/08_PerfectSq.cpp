/*
279. Perfect Squares

Question Link-->>>

https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve1(int n, vector<int> &dp)
    {
        // base case
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            int an = i * i;
            ans = min(ans, 1 + solve1(n - an, dp));
        }
        return dp[n] = ans;
    }

    int solvetab(int n)
    {
        vector<int> dp(n + 1, 0);
        // base case
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++)
            {
                int an = j * j;
                dp[i] = min(dp[i], 1 + dp[i - an]);
            }
        }
        return dp[n];
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        // return solve1(n,dp);
        return solvetab(n);
    }
};