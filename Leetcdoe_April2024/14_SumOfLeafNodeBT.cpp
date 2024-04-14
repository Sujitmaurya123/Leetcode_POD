/*
404. Sum of Left Leaves

Question Link ->
https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

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
    int sum;
    void DFS(TreeNode *root)
    {
        if (root->left != NULL)
        {
            if (root->left->left == NULL && root->left->right == NULL)
            {
                sum += root->left->val;
            }

            DFS(root->left);
        }
        if (root->right != NULL)
        {
            DFS(root->right);
        }
    }

    int sumOfLeftLeaves(TreeNode *root)
    {

        // BFS

        /*   if(root==NULL)return 0;

           queue<pair<TreeNode*,bool>>qt;
           qt.push({root,false});

           int sum=0;
           while(!qt.empty()){
               auto [node,isleft]=qt.front();
               qt.pop();

               if(isleft&& node->left==NULL && node->right==NULL){
                   sum+=node->val;
               }
               if(node->left){
                   qt.push({node->left,true});
               }
               if(node->right){
                   qt.push({node->right,false});
               }
           }
           return sum;
           */

        // DFS

        sum = 0;
        DFS(root);
        return sum;
    }
};