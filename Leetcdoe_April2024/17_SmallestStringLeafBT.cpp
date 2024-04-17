/*
988. Smallest String Starting From Leaf
Question Link ->
https://leetcode.com/problems/smallest-string-starting-from-leaf/submissions/1234539249/?envType=daily-question&envId=2024-04-17
*/

#include<bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
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
    string ans = "";
    void DFS(TreeNode *root, string curr)
    {
        // base case
        if (root == NULL)
            return;
        curr = char(root->val + 'a') + curr;
        if (!root->left && !root->right)
        {
            if (ans == "" || ans > curr)
            {
                ans = curr;
            }
            return;
        }

        DFS(root->left, curr);
        DFS(root->right, curr);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string curr = "";
        DFS(root, curr);
        return ans;
    }
};