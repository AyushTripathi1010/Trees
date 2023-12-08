// Probem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

// INTUITION: In PostOrder Traversal, we follow the order Left -> Right -> Root. So in the 1st stack, we push the 
// left node , then the right node, an push their parent node inside the 2nd stack. 
// Eventually we get the post order in the 2nd stack.

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
    vector<int> postorderTraversal(TreeNode* root) {
          stack<TreeNode*> st1;
          stack<TreeNode*> st2;
          
          vector<int> ans;
          if(!root) return ans;

          st1.push(root);

          while(!st1.empty())
          {
              auto node = st1.top();
              st1.pop();

              st2.push(node);
              if(node->left) st1.push(node->left);

              if(node->right) st1.push(node->right);

          }

          while(!st2.empty())
          {
              auto node = st2.top();
              st2.pop();

              ans.push_back(node->val);
          }

          return ans;
    }
};