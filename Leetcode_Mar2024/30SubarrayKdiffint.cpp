/*
992. Subarrays with K Different Integers

https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atmost(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        while (j < n)
        {
            mp[nums[j]]++;
            while (mp.size() > k && i <= j)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            j++;
            ans += (j - i + 1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};