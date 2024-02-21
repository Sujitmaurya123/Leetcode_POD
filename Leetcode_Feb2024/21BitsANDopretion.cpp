/*
201. Bitwise AND of Numbers Range

Question Link -->>

https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // 1. solve  ->> TLE  T.C => o(2^32-1)
        //     int ans=left;
        //    for(int i=left;i<=right;i++){
        //        ans=(ans&i);
        //    }
        //     return ans;

        // 2 . solution  O(32) -> O(1) TC

        // while(right>left){
        //     right=(right&right-1);
        // }
        // return right;

        // 3 solution
        // s = shift;
        int s = 0;
        while (left < right)
        {
            left >>= 1;  // l left
            right >>= 1; // r right
            s++;
        }
        return left << s;
        // left =5  right=7
        // s=0 to s=2 opration above code
        // left and right both same then 1
        // left<<s  -> 1<<2 => 100 =4
        // ans=4 of [5,7] ka
    }
};