/*
129. Sum Root to Leaf Numbers
Question Link ->
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

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
    // int solve(TreeNode*root,int currsum){
    //     // base case
    //     if(root==NULL)return 0;
    //     currsum=currsum*10+root->val;
    //     if(root->left==NULL && root->right==NULL){
    //         return currsum;
    //     }
    //     int leftsum=solve(root->left,currsum);
    //     int rightsum=solve(root->right,currsum);
    //     return leftsum+rightsum;
    // }
    int sumNumbers(TreeNode *root)
    {
        // int currsum=0;

        // return solve(root,currsum);

        int totalsum = 0;

        queue<pair<TreeNode *, int>> qt;
        qt.push({root, 0});

        while (!qt.empty())
        {
            auto [root, currsum] = qt.front();
            qt.pop();

            currsum = currsum * 10 + root->val;

            if (root->left == NULL && root->right == NULL)
            {
                totalsum += currsum;
            }

            if (root->left)
            {
                qt.push({root->left, currsum});
            }
            if (root->right)
            {
                qt.push({root->right, currsum});
            }
        }
        return totalsum;
    }
};