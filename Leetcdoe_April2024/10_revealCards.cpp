/*
950. Reveal Cards In Increasing Order

Question Link ->
https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        queue<int> qt;

        for (int i = 0; i < n; i++)
            qt.push(i);
        sort(deck.begin(), deck.end());

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[qt.front()] = deck[i];
            qt.pop();
            if (!qt.empty())
            {
                qt.push(qt.front());
                qt.pop();
            }
        }
        return ans;
    }
};