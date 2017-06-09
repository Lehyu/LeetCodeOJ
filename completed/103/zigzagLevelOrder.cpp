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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    TreeNode* node;
    queue<TreeNode*> q;
    q.push(root);
    int index = 0;
    int cur_size = 1;
    int next_size = 1;
    vector<int> lv;
    bool flag = false;
    while(!q.empty()){
      node = q.front();
      q.pop();
      next_size += (node->left != NULL) + (node->right != NULL);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
      index++;
      lv.push_back(node->val);
      if(index == cur_size){
	if(flag) reverse(lv.begin(), lv.end());
	ans.push_back(lv);
	cur_size = next_size;
	lv.clear();
	flag = !flag;
      }
    }
    return ans;
  } 

  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
      return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
      int size = nodesQueue.size();
      vector<int> row(size);
      for (int i = 0; i < size; i++) {
	TreeNode* node = nodesQueue.front();
	nodesQueue.pop();

	// find position to fill node's value
	int index = (leftToRight) ? i : (size - 1 - i);

	row[index] = node->val;
	if (node->left) {
	  nodesQueue.push(node->left);
	}
	if (node->right) {
	  nodesQueue.push(node->right);
	}
      }
      // after this level
      leftToRight = !leftToRight;
      result.push_back(row);
    }
    return result;
  }
};
