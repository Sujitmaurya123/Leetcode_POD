/*
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]


Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // int n=temperatures.size();
        // vector<int>ans(n,0);
        // stack<pair<int,int>>st;

        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && st.top().first<=temperatures[i]){
        //         st.pop();
        //     }
        //     if(!st.empty() ){
        //         ans[i]=st.top().second-i;
        //     }
        //     st.push({temperatures[i],i});
        // }
        // return ans;

        int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (temperatures[i] >= hottest)
            {
                hottest = temperatures[i];
                continue;
            }
            int days = 1;
            while (temperatures[i + days] <= temperatures[i])
            {
                days += ans[i + days];
            }
            ans[i] = days;
        }
        return ans;
    }
};