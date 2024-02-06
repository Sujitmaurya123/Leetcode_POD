/*
49. Group Anagrams

Question Link---->>>

https://leetcode.com/problems/group-anagrams/?envType=daily-question&envId=2024-02-06

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto sk : strs)
        {
            string oristr = sk;
            sort(sk.begin(), sk.end());
            mp[sk].push_back(oristr);
        }
        vector<vector<string>> aks;
        for (auto [key, value] : mp)
        {
            aks.push_back(value);
        }
        return aks;
    }
};