/*
997. Find the Town Judge

Question Link -->>

https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {

        // vector<int> trusting(n + 1, 0);
        // vector<int> trusted(n + 1, 0);
        // for (auto i : trust) {                    // Count trust relationships
        //     trusting[i[0]]++;                    // Increment trust given
        //     trusted[i[1]]++;                    // Increment trust received
        // }
        // int ans = -1;                            // Initialize result

        // for (int i = 1; i <= n; i++)           // Find the person trusted by everyone else
        //     if (trusting[i] == 0 && trusted[i] == n - 1){
        //         ans = i;             // Update result
        //     }
        // return ans;

        vector<int> trustcount(n + 1, 0);

        // Count trust relationships
        for (const auto &relation : trust)
        {
            trustcount[relation[0]]--;
            trustcount[relation[1]]++;
        }
        for (int i = 1; i <= n; ++i)
        { // Check if there is a person who is trusted by everyone else
            if (trustcount[i] == n - 1)
            {
                return i;
            }
        }
        return -1; // If no such person found, return -1
    }
};