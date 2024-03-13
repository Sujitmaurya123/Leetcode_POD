/*

2485. Find the Pivot Integer
Question Link ->
https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        /*
           // simple approach
           for(int i=1;i<=n;i++){
            int    lsum=0,rsum=0;

               for(int j=1;j<=i;j++){
                   lsum+=j;
               }
               for(int k=i;k<=n;k++){
                   rsum+=k;
               }
               if(lsum==rsum){
                   return i;
               }
           }
           return -1;
                           */

        /*
            // two pointer

            int left=1,right=n;
            int lsum=1,rsum=n;
            if(n==1)return n;
            while(left<right){
                 if(lsum<rsum){
                    left++;
                    lsum+=left;
                }else{
                    right--;
                    rsum+=right;
                }

                if(lsum==rsum && left+1==right-1){
                    return left+1;
                }
            }
            return -1;    */

        // Math

        int sum = n * (n + 1) / 2;

        int x = sqrt(sum);

        return x * x == sum ? x : -1;
    }
};