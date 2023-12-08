// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

// INTUITION: Since Preorder means Root -> Left -> Right. But Since We are doing using iteravtive approach, we need to
// Follow the order Root -> Right -> Left, because if we storing these nodes in the stack, and if i push the right
// node first and then the left node, then it is obvious that i will be popping left node first because it is at the top.
/*
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
    vector<int> preorderTraversal(TreeNode* root) {
          
          stack<TreeNode*> st;
         vector<int> ans;
         if(!root) return ans;

          st.push(root);

          while(!st.empty()) {
               
               auto node = st.top();
               st.pop();
               
               ans.push_back(node->val);

               if(node->right) {
                   st.push(node->right);
               }
               
               if(node->left) {
                   st.push(node->left);
               }
          }

          return ans;
    }
};