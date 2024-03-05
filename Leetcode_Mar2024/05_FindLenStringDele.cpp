/*
1750. Minimum Length of String After Deleting Similar Ends


https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j && s[i] == s[j])
        {
            char sk = s[i];

            while (i < j && s[i] == sk)
            {
                i++;
            }
            while (i <= j && s[j] == sk)
            {
                j--;
            }
        }
        return j - i + 1;
    }
};