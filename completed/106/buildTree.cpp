/*
  Given inorder and postorder traversal of a tree, construct the binary tree.
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
preorder: root->left->right
inorder: left->root->right
postorder: left->right->root
*/
class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0) return NULL;
    vector<int> linorder, lpostorder, rinorder, rpostorder;
    int val = postorder[postorder.size()-1];
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), val);
    if(it != inorder.begin()){
      linorder = vector<int>(inorder.begin(), it);
      lpostorder = vector<int>(postorder.begin(), postorder.begin()+linorder.size());
    }
    if(it != inorder.end()-1){
      rinorder = vector<int>(it+1, inorder.end());
      rpostorder = vector<int>(postorder.begin()+linorder.size(), postorder.end()-1);
    }
    TreeNode* root = new TreeNode(val);
    root->left = buildTree(linorder, lpostorder);
    root->right =buildTree(rinorder, rpostorder);
    return root;
  }
};
