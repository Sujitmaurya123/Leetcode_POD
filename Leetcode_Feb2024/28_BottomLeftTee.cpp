/*
513. Find Bottom Left Tree Value

Question Link -->>

https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28

*/

// Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
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
    int maxdeft;
    int value;
    void dfs(TreeNode *root, int deft)
    {
        // base case
        if (root == NULL)
            return;

        if (deft > maxdeft)
        {
            maxdeft = deft;
            value = root->val;
        }
        dfs(root->left, deft + 1);
        dfs(root->right, deft + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        maxdeft = -1;
        value = 0;
        dfs(root, 0);
        return value;
    }
};