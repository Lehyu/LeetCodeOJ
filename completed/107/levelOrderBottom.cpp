/*
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
   one simple solution: use stack<vector<int>>/ans.insert(ans.begin(), val)
*/
class Solution {
public:
  // stack 6ms, insert 13ms
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    //stack<vector<int>> record;
    while(!q.empty()){
      vector<int> sub;
      int len = q.size();
      for(int i = 0; i < len; i++){
	TreeNode* node = q.front();
	q.pop();
	if(node->left) q.push(node->left);
	if(node->right) q.push(node->right);
	sub.push_back(node->val);
      }
      //record.push(sub);
      insert(ans.begin(), sub);
    }
    /*
    while(!record.empty()){
        vector<int> sub = record.top();
        record.pop();
      ans.push_back(sub);
      }*/
    return ans;
  }
};
