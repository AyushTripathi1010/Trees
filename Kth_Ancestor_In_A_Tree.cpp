//  Problem Link: https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

// INTUITION: Here we have to find the kth ancestor or kth parent for a given node. This simply means that we will have to traverse
// upwards, for which we will create binary tree into undirected graph.
// and then loop the map until k gets exhausted also if value of k is large, such if, that node doesn;t exist we will return -1.

//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void makeUnidirected(Node *node, unordered_map<int,int> &parent)
{
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();
        
        if(curr_node->left)
        {
            q.push(curr_node->left);
            parent[curr_node->left->data] = curr_node->data;
        }
        
        if(curr_node->right)
        {
            q.push(curr_node->right);
            parent[curr_node->right->data] = curr_node->data;
        }
        
    }
}
Node *getNode(Node *root, int node)
{   
    if(!root) return NULL;
    if(root->data == node)
    {
        return root;
    }
    
    Node *lft = getNode(root->left, node);
    Node *rht = getNode(root->right, node);
    
    if(!lft && !rht) return NULL;
    
    if(!lft) return rht;
    
     return lft;
    
    
}
int kthAncestor(Node *root, int k, int node)
{
    unordered_map<int,int> parent;
    makeUnidirected(root, parent);
    
    Node *target = getNode(root, node);
    int ans = target->data;
    while(k--)
    {
        if(parent.count(ans))
        {
            ans = parent[ans];
        }
        else
        {
            ans = -1;
            break;
        }
    }
    
    return ans;
    
}