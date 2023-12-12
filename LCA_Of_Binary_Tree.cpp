// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// INTUITION: Here we are given 2 nodes, and our task is to return the lowest common ancestor, of the 2 nodes i.e their deepest
// parent node.

// Here we have to do normal traversal, but also keep in mind certain condtitons like: 
// if -> both lft and rht are NULL, then return NULL, which means both the nodes p and q are not present here.
// if -> one of them is NULL and other is a node, this means we have found one node, so we will return that node.
// if -> both lft and rht are not NULL, that means we have got both the nodes, and we will return their root node, which will be our lca.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* getLCA(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if(!node) return NULL;
        
        if(node == p || node == q) return node;
        TreeNode *lft = getLCA(node->left, p, q);

        TreeNode *rht = getLCA(node->right, p, q);

        if(!lft && !rht) return NULL;

        if(!lft) return rht;

        if(!rht) return lft;

        return node; // means we have got the lca node.
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            
            return getLCA(root, p, q);
    }
};