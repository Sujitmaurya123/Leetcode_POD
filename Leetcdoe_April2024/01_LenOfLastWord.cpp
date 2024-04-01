/*
58. Length of Last Word

Question Link->
https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stack<char> sk;
        int n = s.size(), cnt = 0;

        for (auto d : s)
        {
            sk.push(d);
        }

        while (sk.top() == ' ')
        {
            sk.pop();
        }
        while (!sk.empty() && sk.top() != ' ')
        {
            cnt++;
            sk.pop();
        }
        return cnt;
    }
};