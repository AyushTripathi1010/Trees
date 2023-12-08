// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// INTUITION: We have to print the 1st level from eft to right and then the 2nd level from right to left.
// and do this alternatively.
// so for even counts we will reverse the array the array and store it in our answer.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                vector<vector<int> > ans;
                  if(!root) return ans;
                queue<TreeNode*> q;

               

                q.push(root);
                     int cnt =0;
                while(!q.empty())
                {      
                    int size = q.size();
                      vector<int> ds;
                      cnt++;
                    for(int i =0 ; i < size ; i++)
                    {      TreeNode *node = q.front();
                           q.pop();
                           ds.push_back(node->val);
                         if(node->left) q.push(node->left);

                         if(node->right) q.push(node->right);
                    }
                        if(cnt%2==0) reverse(ds.begin() , ds.end());
                    ans.push_back(ds);
                }

                return ans;
    }
};