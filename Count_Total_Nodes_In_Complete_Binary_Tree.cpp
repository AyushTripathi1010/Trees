// Problem Link: https://leetcode.com/problems/count-complete-tree-nodes/

// INTUITION: Here we have to find the number of nodes in a complete binary tree. WE know the property of Binary Tree, that 
// no. of nodes = 2^h -1; , where h is height of the binary tree.

// SO the Brute Force approach suggests that traverse the whole binary tree and count the nodes.

// But the optimal approach is O(log(n))^2, where we first find the left height and right height by checking the leftmost and rightmost height, and then
// if both heights are equal, this means that subtree is a complete binary tree, and no need to further go down. WE can just directly apply the formula. 
// otherwise we will further go down in subtrees and check for a complete binary tree.

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
    int countNodes(TreeNode* root) {
          
          if(!root) return 0;
          int lftHeight = FindLftHeight(root);
          int rhtHeight = FindRhtHeight(root); 

          if(lftHeight == rhtHeight) return (1<<lftHeight)-1;

          return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int FindLftHeight(TreeNode *node)
    {
        int height = 0;
         while(node)
         {
             height++;
             node= node->left;
         }

         return height;
    }

    int FindRhtHeight(TreeNode *node)
    {
        int height= 0;
        while(node)
        {
            height++;
            node = node->right;
        }

        return height;
    }
};