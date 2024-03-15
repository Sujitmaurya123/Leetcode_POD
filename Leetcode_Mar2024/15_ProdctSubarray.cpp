/*
238. Product of Array Except Self
Question Link->
https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // int n=nums.size();
        // vector<int>pre(n,1),suff(n,1);

        // for(int i=1;i<n;i++){
        //     pre[i]=pre[i-1]*nums[i-1];
        // }
        // for(int i= n-2;i>=0;i--){
        //     suff[i]=suff[i+1]*nums[i+1];
        // }

        // for(int i=0;i<n;i++){
        //     nums[i]=pre[i]*suff[i];
        // }
        // return nums;

        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suffpro = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suffpro = suffpro * nums[i + 1];
            ans[i] = ans[i] * suffpro;
        }
        return ans;
    }
};