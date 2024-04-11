/*
Remove K Digits
Question Link->
https://leetcode.com/problems/remove-k-digits/description/?envType=daily-question&envId=2024-04-11

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> st;
        // 1. remove large nums on stack
        for (auto sk : num)
        {
            while (!st.empty() && st.top() > sk && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(sk);
        }
        // remove k>0 than stack   ans monotonic stack mean incearing num
        while (k > 0)
        {
            st.pop();
            k--;
        }
        // ans
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        int endindex = 0;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (ans[i] != '0')
            {
                endindex = i;
                break;
            }
        }
        ans = ans.substr(0, endindex + 1);
        reverse(ans.begin(), ans.end());
        if (ans == "")
            return "0";
        return ans;
    }
};