// Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

// Link: here we have to find the width of binary tree, i.e no. of nodes between the left most and right most node
// of a level. SO we can find the maximum width using indexing of nodes, fro indexing we can directly subtract the first and last index nodes for each
// level.

// To Note: Since index can overflow, because of the formula 2*i+1, 2*i+2. So we will subtract each nodes for a level by the first index node of that level.
// this will help us to reduce the index value, and avoid index overflow.


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
    int widthOfBinaryTree(TreeNode* root) {
           
           queue<pair<TreeNode*,long long>> q;

           q.push({root,1}); // node, index
           int ans = 0;
           while(!q.empty())
           {
               int sz = q.size();
               
               int first_idx  = q.front().second;
               int last_idx = q.back().second;
               int mmin = first_idx;
               for(int i =0 ; i < sz; i++)
               {
                   TreeNode *node = q.front().first;
                   int curr_idx = q.front().second- mmin;
                   q.pop();

                
                   if(node->left) q.push({node->left, 1ll*2*curr_idx + 1});

                   if(node->right) q.push({node->right, 1ll*2*curr_idx+2});

               }

               ans = max(ans, last_idx-first_idx+1);
           }

           return (int)ans;

    }
};