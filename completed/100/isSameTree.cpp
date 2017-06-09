/*Given two binary trees, write a function to check if they are equal or not.

  Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return inorder(p, q);
  }

  bool inorder(TreeNode*p, TreeNode* q){
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    if(p == NULL && q == NULL) return true;
    bool flag = inorder(p->left, q->left);
    if(!flag) return flag;
    if(p->val != q->val) return false;
    flag = inorder(p->right, q->right);
    return flag;
  }
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }
};
