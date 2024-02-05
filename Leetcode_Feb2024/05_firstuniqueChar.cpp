/*
387. First Unique Character in a String
Question Link-->>>

https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        //    std::unordered_map<char, int> freq_map;

        //     // Count character frequencies
        //     for (char c : s) {
        //         freq_map[c]++;
        //     }

        //     // Find the first unique character
        //     for (int i = 0; i < s.length(); ++i) {
        //         if (freq_map[s[i]] == 1) {
        //             return i;
        //         }
        //     }

        //     // If no unique character is found
        //     return -1;
        vector<int> oc(26);
        // store frequency of each character of s
        for (auto i : s)
            oc[i - 'a']++;
        // first character with frequency = 1 is the answer
        for (int i = 0; i < s.size(); i++)
        {
            if (oc[s[i] - 'a'] == 1)
                return i;
        }
        // no character with frequency = 1
        return -1;
    }
};