/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/



/*
    Each node in a tree has its own diameter, which is calculated by:
        left_depth - depth + right_depth - depth
    where depth is current node's depth in this tree, and left_depth is left child tree's depth (right vice verse).
    So calculate each node's depth as well as diameter in DFS, update max_diameter in the process.
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        max_diameter = 0;
        DFS(root, 0);
        return max_diameter;
    }
    int DFS(TreeNode* root, int depth) {
        if (root->left == NULL && root->right == NULL)
            return depth;
        int left_depth = depth;
        if (root->left != NULL)
            left_depth = DFS(root->left, depth + 1);
        int right_depth = depth;
        if (root->right != NULL)
            right_depth = DFS(root->right, depth + 1);
        // Current-node-root tree's max depth
        int max_depth = max(left_depth, right_depth);
        // Current-node-root tree's diameter
        int diameter = left_depth - depth + right_depth - depth;
        if (diameter > max_diameter)
            max_diameter = diameter;
        return max_depth;
    }
private:
    int max_diameter;
};