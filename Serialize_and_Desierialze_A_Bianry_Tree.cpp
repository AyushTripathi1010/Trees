// Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// INTUITION: Here we are given a binary tree and we have to convert the binary tree in string format, where NULL will be represented by '#', and normal value will
// be converted to string using stoi().

// Then in deserializing we have to again create it into binary tree, using the string formed. So here we will be breaking the string using the ',' as a delimiter.
// We will use stringstream class of which s is an object according to our code, and we pass data a paramter. Then we are also using str string for storiing each character 
// we get from the string.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
          
          if(!root) return "";
          string str ="";
          queue<TreeNode*> q;
          q.push(root);

          while(!q.empty())
          {
              TreeNode *node = q.front();
              q.pop();

              if(node == NULL)
              {
                  str.append("#,");
              }
              else
              {
                  str.append(to_string(node->val)+ ',');
                  q.push(node->left);
                  q.push(node->right);
                  
              }
              
          }

          return str;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
           string str;
           if(data.size() == 0) return NULL;
           stringstream s(data);

           getline(s, str, ',');
           queue<TreeNode*> q;
           TreeNode *root = new TreeNode(stoi(str));
           q.push(root);

           while(!q.empty())
           {
               TreeNode *node = q.front();
               q.pop();

               getline(s, str, ',');

               if(str == "#")
               {
                   node->left = NULL;
               }
               else
               {
                   TreeNode *leftNode = new TreeNode(stoi(str));
                   node->left = leftNode;
                   q.push(node->left);
               }

               getline(s, str, ',');

               if(str == "#")
               {
                   node->right = NULL;
               }
               else
               {
                   TreeNode *rightNode = new TreeNode(stoi(str));
                   node->right = rightNode;
                   q.push(node->right);
               }
           }

           return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));