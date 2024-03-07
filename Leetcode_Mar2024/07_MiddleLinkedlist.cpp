/*
876. Middle of the Linked List

Question Link->

https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

*/


// Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        /*  // 1 solve Slow and fast Pointer Two Pinter

          ListNode*slow=head;
          ListNode*fast=head;

          while(fast!=NULL && fast->next!=NULL){
              fast=fast->next->next;
              slow=slow->next;
          }

          return slow;
          */

        // 2 general methord

        int n = 0;

        ListNode *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        int p = n / 2;
        ListNode *Main = head;
        while (p > 0)
        {
            Main = Main->next;
            p--;
        }
        return Main;
    }
};