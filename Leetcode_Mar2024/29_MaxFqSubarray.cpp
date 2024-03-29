/*
2962. Count Subarrays Where Max Element Appears at Least K Times

Question Link ->
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.



Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxi = 0, i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;
        long long ansk = 0;

        for (auto d : nums)
            maxi = max(maxi, d);

        while (j < n)
        {
            if (nums[j] == maxi)
                mp[nums[j]]++;

            while (mp[maxi] >= k)
            {
                ansk += (n - j);
                if (nums[j] == maxi)
                    --mp[nums[i]];
                i++;
            }
            j++;
        }
        return ansk;
    }
};