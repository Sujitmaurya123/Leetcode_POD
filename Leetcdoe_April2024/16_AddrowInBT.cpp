/*
623. Add One Row to Tree
Question Link ->
https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16

*/

#include<bits/stdc++.h>
using namespace std;


 //Definition for a binary tree node.
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
    void DFS(TreeNode *root, int val, int depth, int currdepth)
    {
        // base case
        if (root == NULL)
            return;

        if (currdepth < depth - 1)
        {
            DFS(root->left, val, depth, currdepth + 1);
            DFS(root->right, val, depth, currdepth + 1);
        }
        if (currdepth == depth - 1)
        {
            TreeNode *exleftnode = root->left;
            TreeNode *exrightnode = root->right;

            TreeNode *newleftnode = new TreeNode(val);
            TreeNode *newrightnode = new TreeNode(val);

            root->left = newleftnode;
            newleftnode->left = exleftnode;

            root->right = newrightnode;
            newrightnode->right = exrightnode;
        }
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *currnode = root;
            TreeNode *newnode = new TreeNode(val);
            newnode->left = currnode;
            return newnode;
        }

        DFS(root, val, depth, 1);
        return root;
    }
};

/*
// BFS

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1){
            TreeNode* ptr=new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        //BFS
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while(!q.empty()){
            auto [node, level]=q.front();
            q.pop();
            if (level==depth-1){
                node->left=new TreeNode(val, ptr, NULL);

                ptr=node->right;
                node->right=new TreeNode(val, NULL, ptr);
            }
            else{
                if (node->left) q.emplace(node->left, level+1);
                if (node->right) q.emplace(node->right, level+1);

            }
        }
        return root;
    }
};

*/