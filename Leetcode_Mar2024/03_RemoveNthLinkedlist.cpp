/*
19. Remove Nth Node From End of List
Question Link -->>
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // find size
        int len = 0;
        ListNode *cu = head;
        while (cu != NULL)
        {
            len++;
            cu = cu->next;
        }

        // find the position
        int t = len - n - 1;
        cu = head;

        // if the head to be remove
        if (t == -1)
        {
            head = head->next;
            delete cu;
            return head;
        }
        // otherwise
        int c = 0;
        while (c < t)
        {
            cu = cu->next;
            c++;
        }
        // remove nth node bro

        ListNode *temp = cu->next;
        cu->next = cu->next->next;
        delete temp;

        return head;
    }
};