/*

2864. Maximum Odd Binary Number

Question Link-->>
https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        // 1 solve TC -> O(nlogn)

        /* sort(s.rbegin(),s.rend());
        int n=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                continue;
            }else{
                swap(s[i-1],s[n]);
                break;
            }
        }
        return s;
        */

        /*  // solve 2 Tc->O(n)

          int cnt=0;
          int n=s.size();
          for(auto d:s){
              if(d=='1')cnt++;
          }
          string ans=string(cnt-1,'1')+string(n-cnt,'0')+'1';
          return ans;

          */

        // 3 solve Two pointer

        int n = s.size();
        int l = 0, r = n - 1;

        while (l <= r)
        {
            if (s[l] == '1')
                l++;
            if (s[r] == '0')
                r--;

            if (l <= r && s[l] == '0' && s[r] == '1')
            {
                swap(s[l], s[r]);
            }
        }
        swap(s[l - 1], s[n - 1]);
        return s;
    }
};