/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */

/*
    注意！！！题目说“You do not necessarily need to follow this format”。
    最初以为必须按照这种格式，采用记录完全二叉树（即所有空节点及空节点的子节点也记录下来）的方式，
    导致当树深度很大时，节点个数过多（可能有很多空节点，例如当树很偏斜的时候），导致内存溢出。
    实际上只要序列化和反序列化采用同一种遍历方式（这里使用前序），即可大大减少编码复杂度。
*/


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
        vector<string> nodes;
        DFS_serialize(root, nodes);
        int len = nodes.size();
        string node_str = "";
        for (int i = 0; i < len - 1; i++) {
            node_str += nodes[i] + ",";
        }
        node_str += nodes[len - 1];
        return node_str;
    }
    
    void DFS_serialize(TreeNode* root, vector<string>& nodes) {
        if (root == NULL) {
            nodes.push_back("#");  // use '#' represent NULL node
            return;
        }
        // remember function 'to_string()'
        nodes.push_back(std::to_string(root->val));
        DFS_serialize(root->left, nodes);
        DFS_serialize(root->right, nodes);
    }

    // Decodes your encoded data to tree. 
    TreeNode* deserialize(string data) {
        int data_len = data.size();
        queue<string> nodes;
        string word;
        for (int i = 0; i < data_len; i++) {
            if (data[i] != ',') {
                word += data[i];
            } else {
                nodes.push(word);
                word.clear();
            }
        }
        if (word.size() > 0)
            nodes.push(word);
        TreeNode* root = DFS_deserialize(nodes);
        return root;
    }
    
    TreeNode* DFS_deserialize(queue<string>& nodes) {
        if (nodes.front() == "#") {
            nodes.pop();
            return NULL;
        }
        // remember function 'stoi()', convert string to int with base 10
        TreeNode* root = new TreeNode( std::stoi(nodes.front()) );
        nodes.pop();
        root->left = DFS_deserialize(nodes);
        root->right = DFS_deserialize(nodes);
        return root;
    }
};
