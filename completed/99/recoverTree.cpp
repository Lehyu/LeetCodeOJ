/*
  Two elements of a binary search tree (BST) are swapped by mistake.

  Recover the tree without changing its structure.

  find two elements in an almost sort array
*/

class Solution {
public:
  TreeNode* first=NULL, *second = NULL, *prev = new TreeNode(INT_MIN);
  void recoverTree(TreeNode* root) {
    
    inorder(root);
    swap(first->val, second->val);
  }

  void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    if(first == NULL && prev->val >= root->val){
      first = prev;
    }
    if(first != NULL && prev->val >= root->val){
      second = root;
    }
    prev = root;
    inorder(root->right);
  }

};
