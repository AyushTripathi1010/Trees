// Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// INTUITION: Here we to access parent nodes in binary tree, we can make this as an undirected graph, and then we can store the parents
// in parent hashmap, we also need a visited map, so that we don't keep on treaversing the same node again and again.
// we need visited because this time we are going in upward direction.

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
    void makeUndirected(TreeNode *node, unordered_map<TreeNode*, TreeNode*> &parent)
    {
         
         queue<TreeNode*> q;
         q.push(node);

         while(!q.empty())
         {
             TreeNode *curr_node = q.front();
             q.pop();

             if(curr_node->left) {q.push(curr_node->left); parent[curr_node->left] = curr_node;}

             if(curr_node->right) {q.push(curr_node->right); parent[curr_node->right] = curr_node;}
         }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
           
           vector<int> ans;
           unordered_map<TreeNode*, TreeNode*> parent;
           makeUndirected(root, parent);
           unordered_map<TreeNode*, bool> visited;
           queue<TreeNode*> q;
           q.push(target);
           visited[target] = true;
           int curr_level = 0;
            

           while(!q.empty())
           {
               int sz = q.size();
               if(curr_level++ == k) break;
               for(int i= 0 ; i < sz; i++)
               {
                   TreeNode *node = q.front();
                   q.pop();
                   
                   if(node->left && !visited[node->left])
                   {
                       q.push(node->left);
                       visited[node->left] = true;
                   }

                   if(node->right && !visited[node->right])
                   {
                       q.push(node->right);
                       visited[node->right] = true;
                   }

                   if(parent[node] && !visited[parent[node]])
                   {
                       q.push(parent[node]);
                       visited[parent[node]] = true;
                   }
               }
              

           }

           while(!q.empty())
           {
               ans.push_back(q.front()->val);
               q.pop();
           }

           return ans;
    }
};