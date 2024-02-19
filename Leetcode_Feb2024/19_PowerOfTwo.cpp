/*
Power OF Two

Question Link -->>
https://leetcode.com/problems/power-of-two/?envType=daily-question&envId=2024-02-19

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {

        // if(n==0)return false;
        // while(n%2==0){
        //     n/=2;
        // }
        // return n==1;

        if (n == 0)
            return false;

        long x = n;
        return (x - (x & -x)) == 0;
    }
};