// Problem Link: https://leetcode.com/problems/same-tree/

// INTUITION: Just move both the tree pointers p and q simultaneously.

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
    bool checkIdentical(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;
        if(p && !q) return false;
        if(!p && q) return false;

        if(p->val != q->val) return false;

        return checkIdentical(p->left, q->left) && checkIdentical(p->right , q->right) && (p->val == q->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
            
            return checkIdentical(p ,q);
    }
};