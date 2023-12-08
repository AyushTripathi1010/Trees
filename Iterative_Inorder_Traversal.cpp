// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

// INTUITION: Here inorder means Left -> Root -> Right. So we first keep on pushing the left nodes, and as we
// get the node as null, it means we have to now pop the top node from the stack and push it in the vector, and it also means that 
// left node has been exhausted, so now move to the right node. And again if we get the node as valid, then we will push it and move to 
// left again.

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
    vector<int> inorderTraversal(TreeNode* root) {
           
           stack<TreeNode*> st;
           vector<int> ans;
           if(!root) return ans;
            TreeNode *node = root;
           while(true) {
               if(node) {
                   st.push(node);
                   node = node->left;
                   }
                
                else {
                    if(st.empty()) break;

                    node = st.top();
                    st.pop();

                    ans.push_back(node->val);
                    node=  node->right;
                }
           }

           return ans;
    }
};