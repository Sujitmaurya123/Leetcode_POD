/*
1614. Maximum Nesting Depth of the Parentheses

Question Lin->
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2024-04-04
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {

        int c = 0, maxi = 0;
        for (auto st : s)
        {
            if (st == '(')
            {
                c++;
                maxi = max(maxi, c);
            }
            else if (st == ')')
            {
                c--;
            }
        }

        return maxi;
    }
};

/*
class Solution {
public:
    int maxDepth(string s) {
        stack<char>sk;
        int n=s.size();
        int c=0,maxi=0;
        for(auto st:s){
             if(st=='('){
                sk.push(st);
            }else if(st==')'){
                maxi=max(maxi,(int)sk.size());
               sk.pop();
            }

        }

        return maxi;
    }
};
*/