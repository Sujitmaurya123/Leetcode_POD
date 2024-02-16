/*
1481. Least Number of Unique Integers after K Removals

Question Link -->>

https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        // 1 solution

        //     unordered_map<int ,int>mp;

        //     for(auto s:arr){
        //         mp[s]++;
        //     }

        //     vector<int>fq;
        //     for(auto m:mp){
        //         fq.push_back(m.second);
        //     }
        //     sort(fq.begin(),fq.end());

        //     int ele=0;
        //     for(int i=0;i<fq.size();i++){
        //         ele+=fq[i];

        //         if(ele>k)return fq.size()-i;
        //     }
        // return 0;

        // 2 way to solution using minHeap

        unordered_map<int, int> mp;

        for (auto s : arr)
        {
            mp[s]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto m : mp)
        {
            minHeap.push(m.second);
        }
        int ele = 0;
        while (!minHeap.empty())
        {
            ele += minHeap.top();

            if (ele > k)
                return minHeap.size();
            minHeap.pop();
        }
        return 0;
    }
};