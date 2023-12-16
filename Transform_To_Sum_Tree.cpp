// Problem Link: https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

// INTUITION: Here we have to change the value of each node with the sum of left and right child, and also we have to return
// the sum of left and right subtree with the current node value.

// We are storing the current node value in data,so that first we can modify the node value, but still be able to use the 
// previous value using data.
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int transform(Node *node)
    {
        if(!node) return 0;
        
        int lft = transform(node->left);
        int rht = transform(node->right);
        
        int data = node->data;
        node->data = lft + rht;
        return data+lft+rht;
        
    }
    void toSumTree(Node *node)
    {
       transform(node);
    }
};


