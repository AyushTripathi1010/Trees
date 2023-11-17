// Problem Link: https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1

// INTUITION: SO here we can join the connections, by considering left pointer as prev, and right pointer as next pointer.
// in terms of circular doubly linked list.

// when we reach the left most node of the binary tree, that is our first node of inorder list. We will consider it as head and prev.
// then while backtracking, my current node will be the root, and prev will be from where i backtracked, so i can connect the previous node
// to the current root, by prev->right = root.
// I also have to join the root to the prev pointer node, so in the tree it is alread joined, but still we wil join it using root->left = prev.

// So now both side connections have been established, now we can move the prev pointer to current root.

// Input:
//      10
//    /    \
//   20    30
//  /  \
// 40  60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40
// Explanation:After converting tree to CDLL,
// when CDLL is is traversed from head to
// tail and then tail to head, elements
// are displayed as in the output. 

// DO a dry run for easy understanding.
class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void inorder(Node *root , Node *&head, Node *&prev)
    {
        if(!root) return;
        
        inorder(root->left, head, prev);
        
        if(!prev)  // this means we have encountered the 1st node of the inorder list.
        {
            head = prev = root;
        }
        else
        {
            prev->right = root;
            prev->right->left = prev;
            prev = prev->right;
        }
        
        inorder(root->right, head, prev);
    }
    Node *bTreeToCList(Node *root)
    {
        
        Node *head = NULL;
        Node *prev = NULL;
        
        inorder(root , head, prev);
        
        head->left = prev;
        prev->right = head;
        
        return head;

    }
};