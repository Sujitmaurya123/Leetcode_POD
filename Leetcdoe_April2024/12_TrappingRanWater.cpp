/*
42. Trapping Rain Water

Question Link->
https://leetcode.com/problems/trapping-rain-water/description/?envType=daily-question&envId=2024-04-12
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // int n=height.size();
        // vector<int>leftmx(n),rightmx(n);
        // int ans=0;
        // if(n==0)return ans;
        // leftmx[0]=height[0];
        // rightmx[n-1]=height[n-1];

        // for(int i=1;i<n;i++){
        //     leftmx[i]=max(leftmx[i-1],height[i]);
        // }
        // for(int i=n-2;i>=0;i--){
        //     rightmx[i]=max(rightmx[i+1],height[i]);
        // }

        // for(int i=0;i<n;i++){
        //     ans+=min(leftmx[i],rightmx[i])-height[i];
        // }
        // return ans;

        int a = 0, b = height.size() - 1;

        int leftmx = 0, rightmx = 0, ans = 0;

        while (a <= b)
        {
            leftmx = max(leftmx, height[a]);
            rightmx = max(rightmx, height[b]);

            if (leftmx < rightmx)
            {
                ans += leftmx - height[a];
                a++;
            }
            else
            {
                ans += rightmx - height[b];
                b--;
            }
        }
        return ans;
    }
};
