/*
  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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
  bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(!root->left && !root->right) return root->val == sum;
    sum -= root->val;
    return hasPathSum(root->left, sum)||hasPathSum(root->right, sum);
  }

  bool DFS(TreeNode* root, int sum){
    if(!root->left && !root->right) return sum==root->val;
    sum -= root->val;
    if(root->left && root->right) return DFS(root->left, sum)||DFS(root->right, sum);
    else if(root->left) return DFS(root->left, sum);
    else return DFS(root->right, sum);
  }
  bool hasPathSum(TreeNode *root, int sum) {
    stack<TreeNode *> s;
    TreeNode *pre = NULL, *cur = root;
    int SUM = 0;
    while (cur || !s.empty()) {
      while (cur) {
	s.push(cur);
	SUM += cur->val;
	cur = cur->left;
      }
      cur = s.top();
      if (cur->left == NULL && cur->right == NULL && SUM == sum) {
	return true;
      }
      if (cur->right && pre != cur->right) {
	cur = cur->right;
      } else {
	pre = cur;
	s.pop();
	SUM -= cur->val;
	cur = NULL;
      }
    }
    return false;
  }
};
