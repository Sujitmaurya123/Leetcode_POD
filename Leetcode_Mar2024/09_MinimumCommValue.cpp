/*
2540. Minimum Common Value
Question Link->
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        /*   //1 two pointer
           int l=0;
           int m=0;
           int sm=INT_MAX;
          while(l<nums1.size() && m<nums2.size()){
              if(nums1[l]==nums2[m]){
                  sm=nums1[l];
                  break;
              }else if(nums1[l]<nums2[m]){
                   l++;
              }else{
                  m++;
              }
          }
          return sm==INT_MAX?-1:sm;;
          */

        unordered_set<int> st(nums1.begin(), nums1.end());

        for (auto el : nums2)
        {
            if (st.contains(el))
            {
                return el;
            }
        }
        return -1;
    }
};