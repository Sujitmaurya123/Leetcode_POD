/*
268. Missing Number

Question Link -->>

https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // 1 solve

        // int p=0;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==p){
        //         p++;
        //     }
        // }
        // return p;

        // 2 solve

        // int n=nums.size();
        // int p=(n*(n+1))/2;
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        // }
        // return p-sum;

        // 3 solve xor

        int xors = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            xors ^= i ^ nums[i];
        }
        return xors;
    }
};