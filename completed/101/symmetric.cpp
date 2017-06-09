/*
  Given a binary tree, check whether it is a mirror of itself 
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

/*
method one: level order, save value in a array, and then check
method two: recursively
*/
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return help(root->left, root->right);
  }

  bool help(TreeNode* node1, TreeNode*node2){
    if(node1 == NULL || node2 == NULL)
      return node1 == node2;
    if(node1->val != node2->val)
      return false;
    /*
    if(node1 == NULL && node2 == NULL){
      return true;
    }
    if((node1 == NULL && node2 != NULL) ||
       (node1 != NULL && node2 == NULL) ||
       (node1->val != node2->val)){
      return false;
      }*/
    return help(node1->left, node2->right) && help(node1->right, node2->left);
  }

  bool isSymmetric(TreeNode* root){
    if(!root) return true;
    TreeNode *left, *right;
    queue<TreeNode*> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty() && !q2.empty()){
      left = q1.front();
      q1.pop();
      right = q2.front();
      q2.pop();
      if(!left && !right) continue;
      if(!left || !right) return false;
      if(left->val != right->val) return false;
      q1.push(left->left);
      q1.push(left->right);
      q2.push(right->right);
      q2.push(right->left);
    }
    return q1.empty()&&q2.empty();
  }
};
