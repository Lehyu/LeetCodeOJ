/*
  Given a binary tree, flatten it to a linked list in-place.
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

// preorder root->left->right
class Solution {
public:
  void flatten(TreeNode* root) {
    if(!root) return;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    TreeNode* now = root;
    if(left){
      root->right = left;
      flatten(left);
      while(now->right) now=now->right;
    }

    now->right = right;
    flatten(right);
  }

};
