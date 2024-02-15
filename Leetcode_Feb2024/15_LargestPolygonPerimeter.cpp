/*
2971. Find Polygon With the Largest Perimeter

Question Link -->>

https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
#define ll long long
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ll summx = nums[0] + nums[1];
        ll ans = 0;

        for (int i = 2; i < nums.size(); i++)
        {
            if (summx > nums[i])
            {
                ans = max(ans, summx + nums[i]);
            }
            summx += nums[i];
        }
        return (ans == 0) ? -1 : ans;
    }
};