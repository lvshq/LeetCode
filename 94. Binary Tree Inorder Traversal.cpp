/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        getInorder(result, root);
        return result;
    }
    
    void getInorder(vector<int> &result, TreeNode* root) {
        if (root == NULL)
            return;
        if (root->left)
            getInorder(result, root->left);
        result.push_back(root->val);
        if (root->right)
            getInorder(result, root->right);
    }
};