/*
Squares OF sort Array
Question Link -->>
https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {

/*
// 1 sove TC - O(nlog n)
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = abs(nums[i] * nums[i]);
        }

        sort(nums.begin(), nums.end());
        return nums;
*/

        // Two Pointer TC - O(n)

int left = 0;
int right = nums.size() - 1;
int n = nums.size();
vector<int> ans(n);
for (int i = n - 1; i >= 0; i--)
{
    int val;

    if (abs(nums[left]) < abs(nums[right]))
    {
        val = nums[right];
        right--;
    }
    else
    { // nums[left]>nums[right]
        val = nums[left];
        left++;
    }
    ans[i] = val * val;
}
return ans;

    }
};