/*
EvenOdd Tree

Question Link -->>
https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

*/


 //Definition for a binary tree node.
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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        TreeNode *cur = root;
        q.push(cur);
        bool level = true;
        ;

        while (!q.empty())
        {
            int sz = q.size();

            int prev = INT_MAX;
            if (level)
                prev = INT_MIN;
            while (sz--)
            {
                cur = q.front();
                q.pop();

                // level is even
                if (level && (cur->val % 2 == 0 || cur->val <= prev))
                    return false;

                // level is odd
                if (!level && (cur->val % 2 == 1 || cur->val >= prev))
                    return false;

                prev = cur->val;

                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
            }
            level = !level;
        }
        return true;
    }
};