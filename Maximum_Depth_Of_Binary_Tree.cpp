// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Intuition: Just Do any Traversal method and while backtracking just add 1.
// to get the height.
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
    int getHeight(TreeNode *node) {
        if(!node) return 0;

        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    int maxDepth(TreeNode* root) {
          
         return  getHeight(root);
    }
};