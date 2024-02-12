/*
169. Majority Element

Question Link -->>

https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // int candidet,n=nums.size();
        // int count=0;

        // for(int i=0;i<n;i++){
        //     if(count==0){
        //         count=1;
        //         candidet=nums[i];
        //     }else{
        //         if(nums[i]==candidet){
        //             count++;
        //         }else{
        //             count--;
        //         }
        //     }
        // }
        // return candidet;

        // unordered_map<int ,int>mp;
        // int h=nums.size()/2;
        // for(auto n:nums){
        //     mp[n]++;
        // }
        // for(auto& [el,fr]:mp){
        //     if(fr>h)return el;
        // }
        // return -1;

        int ct = 0, majorityel = -1;

        for (int n : nums)
        {
            if (ct == 0)
                majorityel = n;
            ct += (n == majorityel) ? 1 : -1;
        }
        return majorityel;
    }
};