// Problem Link : https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

// INTUITION: Here we have to balance the BST such that we get the minimum possible height of the BST. So we can apply recursive binary
// search on the inorder array, as inorder gives the bst in sorted order.
// and will give the hight of log(n).
struct Node
{
	int data;
	Node* left, *right;
};


class Solution{
    
    public:
    void inorder(Node *root, vector<Node*> &v)
    {
        if(!root) return;
        
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
        
        
    }
    
    Node *build(vector<Node*> &v, int lo , int high)
    {
        if(lo > high) return NULL;
        
        int mid = (lo + high)/2;
        
        Node *root = v[mid];
        root->left = build(v,lo, mid-1);
        root->right = build(v, mid+1, high);
        
        return root;
    }
   
    Node* buildBalancedTree(Node* root)
    {
    	vector<Node*> v;
    	inorder(root, v);
    	int high = v.size()-1;
    	
    	return build( v, 0, high);
    }
};
