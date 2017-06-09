/*
  Given a binary tree, determine if it is a valid binary search tree (BST).

  Assume a BST is defined as follows:

  The left subtree of a node contains only nodes with keys less than the node's key.
  The right subtree of a node contains only nodes with keys greater than the node's key.
  Both the left and right subtrees must also be binary search trees.
*/

class Solution {
public:
  // save history info
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }

  bool isValidBST(TreeNode* root, long min_val, long max_val){
    if(root == NULL) return true;
    if(root->val >= max_val || root->val <= min_val) return false;
    return isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val);
  }
};
