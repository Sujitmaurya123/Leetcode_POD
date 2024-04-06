/*
1249. Minimum Remove to Make Valid Parentheses
Question Link->
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans = "";
        int n = s.size();
        int diff = 0, cntopen = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                diff++;
                cntopen++;
                ans.push_back(s[i]);
            }
            else if (s[i] == ')')
            {
                if (diff == 0)
                    continue;
                diff--;
                ans.push_back(s[i]);
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        string fans = "";
        int time = cntopen - diff;

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == '(')
            {
                time--;
                if (time < 0)
                    continue;
            }
            fans.push_back(ans[i]);
        }
        return fans;
    }
};

/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        unordered_set<int>set;
        stack<int>st;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
              if(st.empty())set.insert(i);
              else st.pop();  
            
            }
        }

        while(!st.empty()){
            set.insert(st.top());
            st.pop();
        }

        for(int i=0;i<n;i++){
            if(!set.contains(i)){
                ans.push_back(s[i]);
            }
        }
        return ans;    


         int n=s.size();
        unordered_set<int>set;
        int diff=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                diff++;
            }else if(s[i]==')'){
              if(diff==0)set.insert(i);
              else diff--;  
            
            }
        }

        for(int i=n-1;i>=0;i--){
            if(s[i]=='('&& diff>0){
                set.insert(i);
                diff--;
            }
        }

        for(int i=0;i<n;i++){
            if(!set.contains(i)){
                ans.push_back(s[i]);
            }
        }
        return ans;

    }
};

*/