// Problem Link: https://leetcode.com/problems/binary-tree-paths/

// INTUITION: Here we have to include all the paths from root to leaf nodes, in form of string. SO we are using normal traversal
// technique, and we stop the traversal at the leaf node.

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
     bool isLeaf(TreeNode *node)
     {
         return node && !node->left && !node->right;
     }
    void getPaths(TreeNode *node, vector<string> &ans, string temp )
    {
        if(isLeaf(node))
        {
            
            ans.push_back(temp);
            return;
        }
         

        
        
        if(node->left) getPaths(node->left, ans, temp+ "->" + to_string(node->left->val));

        if(node->right) getPaths(node->right, ans, temp+ "->" + to_string(node->right->val));

    }
    vector<string> binaryTreePaths(TreeNode* root) {
             
             vector<string> ans;
             if(!root)
             return ans;

             string temp = to_string(root->val);
             getPaths(root, ans, temp);

             return ans;
    }
};