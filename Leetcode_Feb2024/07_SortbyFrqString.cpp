/*
451. Sort Characters By Frequency


Question Link --->>>

https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        // 1 solution

        //     vector<int>fq(128,0);
        //     for(char c:s){
        //         fq[c]++;
        //     }
        //    auto cmp=[&](char a,char b){
        //        if(fq[a]==fq[b])return a<b;
        //        return fq[a]>fq[b];
        //    };
        //    sort(s.begin(),s.end(),cmp);
        //    return s;

        // 2 solution

        // unordered_map<char,int>mp;
        // for(auto c:s)mp[c]++;

        // vector<pair<char,int>>fq;
        // for(auto [f1,f2]:mp)fq.push_back({f1,f2});

        // auto cmp=[&](pair<char,int>&a,pair<char,int>&b){
        //     return a.second>b.second;
        // };
        // sort(fq.begin(),fq.end(),cmp);
        // string as="";
        // for(auto [f1,v1]:fq){ as.append(v1,f1);}

        // return as;
        // 3 solution

        unordered_map<char, int> mp;
        for (auto c : s)
            mp[c]++;

        vector<vector<char>> bucket(s.length() + 1);
        for (auto [ch, fq] : mp)
            bucket[fq].push_back(ch);

        string as = "";
        for (int fq = s.length(); fq >= 1; fq--)
        {
            for (auto ch : bucket[fq])
            {
                as.append(fq, ch);
            }
        }
        return as;
    }
};