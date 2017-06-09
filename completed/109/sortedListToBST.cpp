/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
  TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return NULL;
    int len = 0;
    ListNode* p = head;
    for(; p; len++, p=p->next);
    return sortedListToBST(head, 0, len);
  }
  ListNode* find(ListNode* head, int pos){
    ListNode* p = head;
    for(int i = 0; i < pos; i++) p = p->next;
    return p;
  }
  TreeNode* sortedListToBST(ListNode* head, int left, int right) {
    if(left >= right) return NULL;
    int mid = (left+right)>>1;
    ListNode* node = find(head, mid);
    TreeNode* root = new TreeNode(node->val);
    root->left = sortedListToBST(head, left, mid);
    root->right = sortedListToBST(head, mid+1, right);
    return root;
  }

  TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
    TreeNode* root;
    if(head == tail) return root;
    if(head->next == tail){
      root = new TreeNode(head->val);
      return root;
    }
    ListNode* mid = head, *temp=head;
    while(temp != tail && temp->next != tail){
      mid = mid->next;
      temp = temp->next->next;
    }
    root = new TreeNode(mid->val);
    root->left = sortedListToBST(head, mid);
    root->right = sortedListToBST(mid->next, tail);
    return root;
  }

};
