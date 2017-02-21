/*
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {    
    ListNode head(INI_MIN);
    ListNode* node = &head;
    while(l1 && l2){
      bool flag = l1->val <= l2->val;
      node->next = flag? l1:l2;
      flag?l1=l1->next:l2=l2->next;
      node = node->next;
    }
    node->next = l1==NULL?l2:l1;
    return head.next;
  }
  
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {    
    ListNode* head = NULL;
    ListNode* node;
    ListNode* p = l1, *q = l2;
    while(p != NULL && q != NULL){
      bool flag = p->val <= q->val;
      int val = flag ? p->val: q->val;
      flag?p=p->next:q=q->next;
      ListNode* tmp = new ListNode(val);
      if(head == NULL){
	head = tmp;
	node = head;
      }else{
	node->next = tmp;
	node = node->next;
      }
    }
    node->next = p==NULL?q:p;
    return head;
  }
};
