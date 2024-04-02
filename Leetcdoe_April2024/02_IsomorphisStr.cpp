/*
205. Isomorphic Strings
Question Link->
https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1;
        unordered_map<char, bool> mp2;

        for (int i = 0; i < s.size(); i++)
        {
            if (mp1.count(s[i]))
            {
                if (mp1[s[i]] != t[i])
                    return false;
            }
            else
            {
                if (mp2.count(t[i]))
                    return false;
                mp1[s[i]] = t[i];
                mp2[t[i]] = true;
            }
        }
        return true;
    }
};