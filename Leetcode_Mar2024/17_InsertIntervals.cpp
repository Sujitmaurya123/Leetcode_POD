/*
57. Insert Interval
Question Link ->
https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;

        int st = newInterval[0], en = newInterval[1], n = intervals.size(), i = 0;
        // if intervals[0]<st  se to ans me pushback karege
        while (i < n && intervals[i][1] < st)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        // merged marege interval ko
        vector<int> mergedInter = {st, en};
        while (i < n && intervals[i][0] <= en)
        {
            mergedInter[0] = min(mergedInter[0], intervals[i][0]);
            mergedInter[1] = max(mergedInter[1], intervals[i][1]);
            i++;
        }
        ans.push_back(mergedInter);

        // bachha huaa
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};