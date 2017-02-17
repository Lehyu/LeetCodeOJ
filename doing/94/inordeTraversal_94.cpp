#include "header.hpp"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
  
};
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root){
    if(root == NULL) return NULL;
    vector<int> tree;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
      TreeNode* tmp = s.top();
      if(tmp->left==NULL) {
	tree.push_back(tmp->val);
	s.pop();
	if(tmp->right!=NULL)s.push(tmp->right);
      }else {
	s.push(tmp->left);
      }
    }
    return tree;
  }
};

int main(){
  vector<int> array{1,0,2,3};
  TreeNode* root = buildTree(array);
  Solution* sl = new Solution;
  vector<int> tree = sl->inorderTraversal(root);
  sl->rcinorder(root);
  /*
  for(int i = 0; i < tree.size(); i++) {
    cout<<tree[i]<<" ";
  }
  cout<<endl;*/
  return 0;
}
  
