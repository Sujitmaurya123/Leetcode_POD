/*
Custom Sort String
Question Link->
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        /*
        auto cmp=[&](char a,char b){
            return order.find(a)<order.find(b);
        };
        sort(s.begin(),s.end(),cmp);
        return s;
        */

        unordered_map<char, int> mp;
        for (auto el : s)
            mp[el]++;
        string ans = "";
        for (auto el : order)
        {
            while (mp[el]-- > 0)
                ans.push_back(el);
        }
        for (auto [a, b] : mp)
        {
            while (b-- > 0)
                ans.push_back(a);
        }
        return ans;
    }
};