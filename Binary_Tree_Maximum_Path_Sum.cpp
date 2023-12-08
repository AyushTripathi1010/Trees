// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

// INTUITION: Here we have to calculate the path which gives the maximum path sum, but since we can have negative value nodes also
// so, for any node we will take sum of current node and sum from left subtree and right subtree. But we will not return this sum, becuase that sum
// could be negative also, and if returned will reduce the sum for above nodes in tree also, so for that reason we have written.
// max(0, getPath(node->left, sum)).


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getPath(TreeNode *node, int &sum)
    {
         if(!node) return 0;

         int lftsum = max(0, getPath(node->left, sum));

         int rhtsum = max(0, getPath(node->right, sum));

         sum = max(sum, lftsum + rhtsum + node->val);

         return node->val + max(lftsum, rhtsum);

    }
    int maxPathSum(TreeNode* root) {
          int sum = INT_MIN;
          
          getPath(root, sum);
          return sum;
    }
};