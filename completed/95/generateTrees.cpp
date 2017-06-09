/*
  Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
  BST: left<=root<=right
  set root fixed
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    if(n <= 0) return vector<TreeNode*>();
    return generateTree(1,n);
  }

  vector<TreeNode*> generateTree(int start, int end){
    vector<TreeNode*> ans;
    if(start>end){
      ans.push_back(NULL);
      return ans;
    }
    if(start == end){
      ans.push_back(new TreeNode(start));
      return ans;
    }
    vector<TreeNode*> left, right;
    for(int i = start; i<=end; i++){
      left = generateTree(start, i-1);
      right = generateTree(i+1, end);
      for(auto lnode = left.begin(); lnode !=left.end(); lnode++){
	for(auto rnode = right.begin(); rnode !=right.end(); rnode++){
	  TreeNode* root = new TreeNode(i);
	  root->left = *lnode;
	  root->right = *rnode;
	  ans.push_back(root);
	}
      }
    }
    return ans;
  }
};
