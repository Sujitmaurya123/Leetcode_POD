/*
Diameter Of  Binary Tree

Question Link -->>

https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27

*/


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
    int maxdiameter = 0;

    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftdeft = dfs(root->left);
        int rightdeft = dfs(root->right);
        maxdiameter = max(maxdiameter, leftdeft + rightdeft);
        return max(leftdeft, rightdeft) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return maxdiameter;
    }
};