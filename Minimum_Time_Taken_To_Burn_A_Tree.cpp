// Problem Link: https://www.geeksforgeeks.org/problems/burning-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// INTUITION: Here we have to find the minimum time taken to burn a tree, from any given node, and from this node,we will move radially 
// outward in all direction, by converting te tree to undircted graph.

// Here since the target address is not given so, we have to search for the node with target value as well.


class Solution {
  public:
    Node *getTarget(Node *node , int target)
    {
          if(!node) return NULL;
          
          if(node->data == target) return node;
          Node *lft = getTarget(node->left , target);
          
          Node *rht = getTarget(node->right , target);
          
          if(!lft && !rht) return NULL;
          if(lft && !rht) return lft;
          
          if(!lft && rht) return rht;
          
    }
    
     void getParent(Node *root ,unordered_map<Node* , Node*> &parent, Node *&t, int target )
     {
         queue<Node*> q;
         
         q.push(root);
         
         
         while(!q.empty())
         {
             Node *node = q.front();
             q.pop();
             
             if(node && node->data == target) t = node;
             
             if(node->left)
             {
                 q.push(node->left);
                 parent[node->left] = node;
                 
             }
             
             if(node->right)
             {
                 q.push(node->right);
                 parent[node->right] = node;
                 
             }
         }
     }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        // task 1 : is to get the address the of the target
        
          Node *targets = getTarget(root , target);
          
          unordered_map<Node* , Node*> parent;
          
         Node *t =NULL;
         getParent(root , parent , t, target);
          
          unordered_map<Node* , bool> visited;
          
          queue<pair<Node*, int>>q;
          
          q.push({t , 0});
          visited[t] = true;
          int ans = 0;
          while(!q.empty())
          {
              Node *node = q.front().first;
              int dist= q.front().second;
              
              ans = max(ans , dist);
               
              q.pop();
              
              if(node->left && !visited[node->left])
              {
                  q.push({node->left , dist+1});
                  visited[node->left] = true;
              }
              if(node->right && !visited[node->right])
              {
                  q.push({node->right , dist+1});
                  visited[node->right] = true;
              }
              
              if(parent[node] && !visited[parent[node]])
              {
                  q.push({parent[node] , dist+1});
                  visited[parent[node]] = true;
              }
          }
          
          return ans;
    }
};