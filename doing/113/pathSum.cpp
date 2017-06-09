/*
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> record;
    DFS(root, sum, ans, record);
    return ans;
  }

  void DFS(TreeNode* root, int sum, vector<vector<int>> & ans, vector<int> record){
    if(!root) return;
    record.push_back(root->val);
    if(!root->left && !root->right){
      if(root->val == sum){
	ans.push_back(record);
      }
    }
    sum -= root->val;
    DFS(root->left, sum, ans, record);
    DFS(root->right, sum, ans, record);
  }
};
