/*
Same Tree

Question Link -->>

https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26

*/

//
 // Definition for a binary tree node.

 #include<bits/stdc++.h>
 using namespace std;
 
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // base case
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;

        if (p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }
};