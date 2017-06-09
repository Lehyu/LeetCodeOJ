/*
  Given preorder and inorder traversal of a tree, construct the binary tree.
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0) return NULL;
    TreeNode* root = new TreeNode(preorder[0]);
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder[0]);
    
    vector<int> inorder1, preorder1;
    if(it != inorder.begin()){
      inorder1 = vector<int>(inorder.begin(), it);
      preorder1 = vector<int>(preorder.begin()+1, preorder.begin()+inorder1.size()+1);
    }
    vector<int> inorder2, preorder2;
    if(it != inorder.end()-1){
      inorder2 = vector<int>(it+1, inorder.end());
      preorder2 = vector<int>(preorder.begin()+inorder1.size()+1, preorder.end());
    }
    root->left = buildTree(preorder1, inorder1);
    root->right = buildTree(preorder2, inorder2);
    return root;
  }
};
