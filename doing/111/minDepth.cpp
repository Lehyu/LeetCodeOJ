/*
  Given a binary tree, find its minimum depth.

  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
  breadth-first search
*/
class Solution {
public:
  int minDepth(TreeNode* root) {
    if(!root) return 0;
    return BFS(root);
  }
  //9ms
  int BFS(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty()){
      int size = q.size();
      depth++;
      for(int i = 0; i < size; i++){
	TreeNode* node = q.front();
	q.pop();
	if(!node->left&&!node->right){
	  return depth;
	}
	if(node->left)q.push(node->left);
	if(node->right)q.push(node->right);
      }
    }
    return depth;
  }
  //12ms
  int DFS(TreeNode* root){
    if(!root) return 0;
    int left = DFS(root->left);
    int right = DFS(root->right);
    return (!left || !right)? left+right+1:min(left, right)+1;
  }
};
