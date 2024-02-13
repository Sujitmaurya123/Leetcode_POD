/*
2108. Find First Palindromic String in the Array

Question Link -->>

https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool isPali(string s)
    {
        int j = s.size() - 1;
        int i = 0;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (auto w : words)
        {
            if (isPali(w))
            {
                return w;
            }
        }
        return "";
    }
};