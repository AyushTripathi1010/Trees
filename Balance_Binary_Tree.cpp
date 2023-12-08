// Problem Link: https://leetcode.com/problems/balanced-binary-tree/

// INTUITION: Here for any node the difference of height of left and right subtree should not exceed 1.
// TO depict that we have got a invalid height difference, we are returning -1.

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
    int checkBalanced(TreeNode *node)
    {
        if(!node) return 0;

        int lftHeight = checkBalanced(node->left);
        if(lftHeight == -1) return -1;
        int rhtHeight = checkBalanced(node->right);
        if(rhtHeight == -1) return -1;
        if(abs(lftHeight - rhtHeight) > 1) return -1;

        return 1 + max(lftHeight, rhtHeight);


    }
    bool isBalanced(TreeNode* root) {
         
         return checkBalanced(root) == -1 ?  false :  true;

    }
};