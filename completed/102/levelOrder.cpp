/*
  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    TreeNode* node;
    queue<TreeNode*> q;
    q.push(root);
    int index = 0;
    int cur_size = 1;
    int next_size = 1;
    vector<int> lv;
    while(!q.empty()){
      node = q.front();
      q.pop();
      if(node->left){
	q.push(node->left);
	next_size++;
      }
      if(node->right){
	q.push(node->right);
	next_size++;
      }
      index++;
      lv.push_back(node->val);
      if(index == cur_size){
	ans.push_back(lv);
	cur_size = next_size;
	lv.clear();
      }
    }
    return ans;
  }


  void buildVector(vector<vector<int>> &ret, TreeNode *root, int depth){
    if(root == NULL) return;
    if(ret.size() == depth)
      ret.push_back(vector<int>());
    
    ret[depth].push_back(root->val);
    buildVector(ret, root->left, depth + 1);
    buildVector(ret, root->right, depth + 1);
  }

  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    buildVector(ret, root, 0);
    return ret;
  }
};
