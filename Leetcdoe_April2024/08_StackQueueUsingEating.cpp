/*
1700. Number of Students Unable to Eat Lunch
Question Link->
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int zerocnt = 0, onecnt = 0;

        for (auto st : students)
        {
            if (st == 0)
            {
                zerocnt++;
            }
            else
            {
                onecnt++;
            }
        }
        for (auto san : sandwiches)
        {
            if (san == 0 && zerocnt == 0)
                return onecnt;
            if (san == 1 && onecnt == 0)
                return zerocnt;

            if (san == 0)
            {
                zerocnt--;
            }
            else
            {
                onecnt--;
            }
        }
        return 0;
    }
};
