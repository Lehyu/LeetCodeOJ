/*
  Given a binary tree, find its maximum depth.

  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
  //breadth-first search 6ms
  int maxDepth(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int depth = 0;
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while ( !nodesQueue.empty()) {
      int size = nodesQueue.size();
      vector<int> row(size);
      for (int i = 0; i < size; i++) {
	TreeNode* node = nodesQueue.front();
	nodesQueue.pop();

	if (node->left) {
	  nodesQueue.push(node->left);
	}
	if (node->right) {
	  nodesQueue.push(node->right);
	}
      }
      depth ++;
    }
    return depth;
  }
  // depth-first search 9ms
  int maxDepth(TreeNode *root){
    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
  }
};
