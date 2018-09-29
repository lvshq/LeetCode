/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/


/*
    Method 1: pre-order traverse. Each node has min_val and max_val of the tree with it self being root.
    A binary search tree should meet these requirments:
    (1) left child's value < current value
    (2) right child's value > current value
    (3) left subtree's max value < current value
    (4) right subtree's min value > current value
    (5) left and right subtree are also BST.
    So method 1 is an implementation of above requirments.
    
    Method 2: in-order traverse.
    Since Binary Search Tree's in-order traverse is an ordered array, we can use this important characteristic.
    As long as some two elements in this array are not ascending, it is not a valid BST.
*/


/*
    Method 1: pre-order traverse. Each node has min_val and max_val of the tree with it self being root.
    A binary search tree should meet these requirments:
    (1) left child's value < current value
    (2) right child's value > current value
    (3) left subtree's max value < current value
    (4) right subtree's min value > current value
    (5) left and right subtree are also BST.
    So method 1 is an implementation of above requirments.
    
    Method 2: in-order traverse.
    Since Binary Search Tree's in-order traverse is an ordered array, we can use this important characteristic.
    As long as some two elements in this array are not ascending, it is not a valid BST.
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
    struct BFSSearch {
        int max_val;
        int min_val;
        bool valid;
        BFSSearch(int max_v, int min_v, int valid): max_val(max_v), min_val(min_v), valid(valid) {}
        BFSSearch(): max_val(0), min_val(0), valid(false) {}
    };
    typedef struct BFSSearch BFSResult;
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        // Method 1: pre-order traverse.
        // return isValid(root).valid;
        
        // Method 2: in-order traverse.
        vector<int> inorder;
        bool valid = true;
        inOrder(root, inorder, valid);
        return valid;
    }
    
    // Method 2: in-order traverse.
    void inOrder(TreeNode* curr, vector<int> &inorder, bool &valid) {
        if (curr->left != NULL)
            inOrder(curr->left, inorder, valid);
        inorder.push_back(curr->val);
        int len = inorder.size();
        // As long as some two elements in this array are not ascending, it is not a valid BST.
        if (len > 1 && inorder[len - 1] <= inorder[len - 2]) {
            valid = false;
            return;
        }
        if (curr->right != NULL)
            inOrder(curr->right, inorder, valid);
    }
    
    // Method 1: pre-order traverse.
    BFSResult isValid(TreeNode* root) {
        int val = root->val;
        BFSResult curr_node(val, val, false);
        if (root->left == NULL && root->right == NULL)  // leaf node's max and min value is itself.
            return BFSResult(val, val, true);
        if (root->left != NULL) {
            if (root->left->val < val) {
                BFSResult left_tree = isValid(root->left);
                if (left_tree.valid && left_tree.max_val < val) {
                    curr_node.min_val = left_tree.min_val;
                    curr_node.valid = true;
                } else {
                    return curr_node;
                }
            } else {  // current tree is invalid
                return curr_node;
            }
        }
        if (root->right != NULL) {
            if (root->right->val > val) {
                BFSResult right_tree = isValid(root->right);
                if (right_tree.valid && right_tree.min_val > val) {
                    curr_node.max_val = right_tree.max_val;
                    curr_node.valid = true;
                    return curr_node;
                } else {
                    curr_node.valid = false;
                    return curr_node;
                }
            } else {  // current tree is invalid
                curr_node.valid = false;
                return curr_node;
            }
        }
        return curr_node;
    }
};
