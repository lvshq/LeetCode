/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/


/*
    A modified version of Tree BFS.
    Need to record a level's nodes, so use two while loop:
    Inner one to iterate level nodes and get all nodes in current level, the outer one to go deeper to next level.
    At last reverse each odd level nodes' order.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if (root == NULL)
            return result;
        q.push(root);
        vector<int> root_row = { root->val };
        result.push_back(root_row);
        while (!q.empty()) {
            vector<int> row_nodes_val;
            vector<TreeNode*> row_nodes;
            while (!q.empty()) {
                TreeNode* n = q.front();
                q.pop();
                if (n->left != NULL) {
                    row_nodes.push_back(n->left);
                }
                if (n->right != NULL) {
                    row_nodes.push_back(n->right);
                }
            }
            
            for (auto node : row_nodes) {
                q.push(node);
                row_nodes_val.push_back(node->val);
            }
            // In the last level, all are null so the size is 0. Should not include this level.
            if (row_nodes_val.size() > 0)
                result.push_back(row_nodes_val);
        }
        int rows = result.size();
        for (int i = 0; i < rows; i++) {
            if (i % 2)
                reverse(result[i].begin(), result[i].end());
        }
    return result;
    }
};