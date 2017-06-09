/*
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
  which means the root val is the median of nums
*/
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
  }

  TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
    if(left > right) return NULL;
    int mid = (left+right)>>1;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid-1);
    root->right = sortedArrayToBST(nums, mid+1, right);
    return root;
  }
};
