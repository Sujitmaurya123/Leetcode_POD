/*
1043. Partition Array for Maximum Sum

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1


Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSumAfterPartitioning(std::vector<int> &arr, int k)
    {
        // Length of the input array
        int n = arr.size();

        // Dynamic programming table to store maximum sum at each position
        std::vector<int> dp(n + 1, 0);

        // Iterate through the array elements
        for (int i = 0; i < n; i++)
        {
            int curMax = 0, curSum = 0;

            // Iterate over the last k elements or until the beginning of the array
            for (int j = i; j >= std::max(0, i - k + 1); j--)
            {
                // Update the maximum value in the current partition
                curMax = std::max(curMax, arr[j]);

                // Calculate the current sum considering the maximum value in the partition
                int cur = curMax * (i - j + 1) + dp[j];

                // Update the current sum if the new one is greater
                curSum = std::max(curSum, cur);
            }

            // Update the dynamic programming table with the maximum sum at the current position
            dp[i + 1] = curSum;
        }

        return dp[n];
    }
};