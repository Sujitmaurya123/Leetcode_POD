/*
525. Contiguous Array
Question ->
https://leetcode.com/problems/contiguous-array/description/?envType=daily-question&envId=2024-03-16
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int presum = 0, ans = 0;
        unordered_map<int, int> firstocc{{0, -1}};

        for (int i = 0; i < nums.size(); i++)
        {
            presum += nums[i] == 1 ? 1 : -1;

            if (firstocc.count(presum))
                ans = max(ans, i - firstocc[presum]);
            else
                firstocc[presum] = i;
        }
        return ans;
    }
};