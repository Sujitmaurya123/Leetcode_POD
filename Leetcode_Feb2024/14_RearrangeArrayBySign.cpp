/*
2149. Rearrange Array Elements by Sign

Question Link -->>

https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
            // 1 solution

        //     vector<int>a;
        //     vector<int>b;

        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]<0){
        //             a.push_back(nums[i]);
        //         }else{
        //             b.push_back(nums[i]);
        //         }
        //     }

        //    for(int i=0;i<nums.size();i++){
        //        if(i%2==0){
        //            nums[i]=b[i/2];
        //        }else{
        //            nums[i]=a[i/2];
        //        }
        //    }
        //    return nums;

        // two pointer approach   2 solution 
        int n = nums.size();
        vector<int> ans(n);
        int po = 0, ng = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                ans[po] = nums[i];
                po += 2;
            }
            else
            {
                ans[ng] = nums[i];
                ng += 2;
            }
        }
        return ans;

        // swap not working  3 solution 

        // int n=nums.size();

        // int p=0,ng=1;
        // while(p<n &&ng<n ){
        //     if(nums[p]>=0)p+=2;
        //     else if(nums[ng]<0)ng+=2;
        //     else swap(nums[p],nums[ng]);
        // }
        // return nums;
    }
};