/*
930. Binary Subarrays With Sum
Question Link->
https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Atmost(vector<int> &nums, int goal)
    {
        int sum = 0, l = 0, r = 0, cnt = 0, n = nums.size();
        for (; r < n; r++)
        {
            sum += nums[r];
            for (; sum > goal; l++)
                sum -= nums[l];
            // add the length of each subarray
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // unordered_map<int,int>mp;

        // int presum=0,ans=0;
        // mp[0]=1;
        // for(auto s:nums){
        //     presum+=s;

        //     if(mp.find(presum-goal)!=mp.end()){
        //         ans+=mp[presum-goal];
        //     }
        //     mp[presum]++;
        // }
        // return ans;

        return goal > 0 ? Atmost(nums, goal) - Atmost(nums, goal - 1) : Atmost(nums, 0);
    }
};