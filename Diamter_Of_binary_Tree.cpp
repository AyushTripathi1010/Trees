// Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/

// INTUITION: Here diamter means that the maximum number of edges between any 2 nodes
// So for that node, we get the maximum left height tree, and maximum right height tree. sotre it in 
// diamter.
// We do this for every node.

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
    
    int getDiamter(TreeNode *node, int &diameter){
        if(!node) return 0;

        int lftHeight = getDiamter(node->left, diameter);

        int rhtHeight = getDiamter(node->right, diameter);

        diameter = max(diameter , lftHeight+ rhtHeight);

        return 1 + max(lftHeight, rhtHeight);


    }
    int diameterOfBinaryTree(TreeNode* root) {
          
          int diameter = INT_MIN;
          getDiamter(root, diameter);

          return diameter;

    }
};