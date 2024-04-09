/*
2073. Time Needed to Buy Tickets

Question Link->
https://leetcode.com/problems/time-needed-to-buy-tickets/?envType=daily-question&envId=2024-04-09

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        // queue<int>qt;
        // for(int i=0;i<tickets.size();i++)qt.push(i);

        // int time=0;
        // while(!qt.empty()){
        //     time++;

        //     int idfront=qt.front();
        //     qt.pop();
        //     tickets[idfront]--;

        //     if(idfront==k&&tickets[idfront]==0)return time;
        //     if(tickets[idfront]!=0)qt.push(idfront);
        // }
        // return 0;

        int time = 0;

        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k] - 1, tickets[i]);
        }
        return time;
    }
};