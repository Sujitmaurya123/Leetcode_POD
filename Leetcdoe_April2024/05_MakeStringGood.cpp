/*
1544. Make The String Great

Question Link->
https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string makeGood(string s)
    {
        // string ans="";

        // for(auto sk:s){
        //     int n=ans.size();

        //     if(n>0 && abs(ans[n-1]-sk)==32){
        //         ans.erase(n-1);
        //     }else{
        //         ans+=sk;
        //     }
        // }
        // return ans;

        stack<char> st;

        for (auto sk : s)
        {

            if (!st.empty() && abs(sk - st.top()) == 32)
            {
                st.pop();
            }
            else
            {
                st.push(sk);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};