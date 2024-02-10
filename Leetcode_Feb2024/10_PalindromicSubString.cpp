/*
647. Palindromic Substrings

Question Link -->>
https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10





Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/



#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int isPalindromic(string &s,int i,int j){
    //     if(i>=j)return 1;
    //     return s[i]==s[j]?isPalindromic(s,i+1,j-1):0;
    // }
    // int countSubstrings(string s) {
    //     int cout=0;
    //     for(int i=0;i<s.size();i++){
    //         for(int j=i;j<s.size();j++){
    //             cout+=isPalindromic(s,i,j);
    //         }
    //     }
    //     return cout;
    // }

    // int isPalindromic(string &s,int i,int j,vector<vector<int>>&dp){
    //     if(i>=j)return 1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     return dp[i][j]=s[i]==s[j]?isPalindromic(s,i+1,j-1,dp):0;
    // }
    // int countSubstrings(string s) {
    //     vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    //     int cout=0;
    //     for(int i=0;i<s.size();i++){
    //         for(int j=i;j<s.size();j++){
    //             cout+=isPalindromic(s,i,j,dp);
    //         }
    //     }
    //     return cout;
    // }

    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int cout = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (i + 1 == j)
                {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                }
                else
                {
                    dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0;
                }
                cout += dp[i][j];
            }
        }
        return cout;
    }
};