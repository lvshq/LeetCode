/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

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
    // Method 1: recursive version: DFS.
    int maxDepth(TreeNode* root) {
        // return DFS(root);
        return BFS(root);
    }
    
    int DFS(TreeNode* root) {
        int depth = 0;
        if (root == NULL)
            return depth;
        depth = 1 + max(maxDepth(root->left), maxDepth(root->right));
        return depth;
    }
    
    // Method 2: iterative version: BFS.
    int BFS(TreeNode* root) {
        int depth = 0;
        if (root == NULL)
            return depth;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* head = q.front();
                q.pop();  // head is pop from the queue
                if (head->left)
                    q.push(head->left);
                if (head->right)
                    q.push(head->right);
            }
        }
        return depth;
    }
};