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
    if(!root) return {};
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
      TreeNode* p = s.top();
      if(p->left){
	s.push(p->left);
	p->left = NULL;
      }else{
	ans.push_back(p->val);
	s.pop();
	if(p->right) s.push(p->right);
      }
    }
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vector;
    stack<TreeNode *> stack;
    TreeNode *pCurrent = root;
        
    while(!stack.empty() || pCurrent)
      {
	if(pCurrent)
	  {
	    stack.push(pCurrent);
	    pCurrent = pCurrent->left;
	  }
	else
	  {
	    TreeNode *pNode = stack.top();
	    vector.push_back(pNode->val);
	    stack.pop();
	    pCurrent = pNode->right;
	  }
      }
    return vector;
  }
  vector<int> inorderTraversal(TreeNode* root){
    vector<int> ans;
    inorder(ans, root);
    return ans;
  }

  void inorder(vector<int> &ans, TreeNode* root){
    if(root == NULL) return;
    inorder(ans, root->left);
    ans.push_back(root->val);
    inorder(ans, root->right);
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
  
