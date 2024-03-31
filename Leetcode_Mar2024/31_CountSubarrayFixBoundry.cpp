/*
2444. Count Subarrays With Fixed Bounds

Question Link->
https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2024-03-31
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int mink, int maxk)
    {
        int mI = -1, mxI = -1;
        long long ans = 0;
        int leftB = -1, n = nums.size();

        for (int cu = 0; cu < n; cu++)
        {
            if (nums[cu] == mink)
            {
                mI = cu;
            }
            if (nums[cu] == maxk)
            {
                mxI = cu;
            }
            // check out of bound
            if (nums[cu] < mink || nums[cu] > maxk)
            {
                leftB = cu;
            }
            if (mI != -1 && mxI != -1)
            {
                int sm = min(mI, mxI);
                if ((sm - leftB) > 0)
                {
                    ans = ans + (sm - leftB);
                }
            }
        }
        return ans;
    }
};