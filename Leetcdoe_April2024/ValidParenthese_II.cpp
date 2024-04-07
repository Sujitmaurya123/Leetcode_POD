/*
678. Valid Parenthesis String
Question Link->
https://leetcode.com/problems/valid-parenthesis-string/submissions/1225696831/?envType=daily-question&envId=2024-04-07
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // stack<int>openBt,star;

        // for(int i=0;i<s.size();i++){
        //     char sk=s[i];
        //     if(sk=='('){
        //         openBt.push(i);
        //     }else if(sk=='*'){
        //         star.push(i);
        //     }else {
        //         if(!openBt.empty()){
        //             openBt.pop();
        //         }else if(!star.empty()){
        //             star.pop();
        //         }else{
        //             return false;
        //         }
        //     }
        // }

        // while(!openBt.empty() && !star.empty()){
        //     if(openBt.top()>star.top()){
        //         return false;
        //     }
        //     openBt.pop();
        //     star.pop();
        // }
        // return openBt.empty();

     
        int opBt=0,clBt=0;
        int n=s.size();
for (int i = 0; i < n; i++)
{
    if (s[i] == '(' || s[i] == '*')
    {
        opBt++;
    }
    else
    {
        opBt--;
    }

    if (s[n - 1 - i] == ')' || s[n - 1 - i] == '*')
    {
        clBt++;
    }
    else
    {
        clBt--;
    }
    if (opBt < 0 || clBt < 0)
        return false;
        }
        return true;
    }
};
