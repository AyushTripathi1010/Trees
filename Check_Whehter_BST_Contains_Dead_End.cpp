// Problem Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

// INTUITION: Here we have toc check for leaf node, on which no more nodes can be inserted. SO we have use the range
// technique. And if anywhere the range is greater than 2 means there is a chance of inserting any other node as well.

// Why greater than 2 ?
// Ans.) Because suppose for node 9 in BST the range looks like [8,10], this means that 9 is the onl node between them. Here we can see
// that 10-8 = 2, that is the requirement for dead end.

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    bool isLeafNode(Node *node)
    {
        return node && !node->left && !node->right;
    }
    bool checkDeadEnd(Node *node, int lb, int ub)
    {   
        
        if(isLeafNode(node))
        {
            if(ub-lb > 2) return false;
            return true;
        }
        if(node->left && checkDeadEnd(node->left, lb, node->data)) return true;
        if(node->right && checkDeadEnd(node->right, node->data, ub)) return true;
        
        return false;
    }
    bool isDeadEnd(Node *root)
    {
        if(!root) return false;
       return checkDeadEnd(root, 0, INT_MAX);
    }
};
