/*
  Given a linked list, remove the nth node from the end of list and return its head.
  For example,

  Given linked list: 1->2->3->4->5, and n = 2.

  After removing the second node from the end, the linked list becomes 1->2->3->5.
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
  ListNode RemoveNthFromEnd(ListNode *head, int n) {
    ListNode *h1=head, *h2=head;
    while(n-->0) h2=h2->next;
    if(h2==null)return head->next;  // The head need to be removed, do it.
    h2=h2->next;
    while(h2!=null){
      h1=h1->next;
      h2=h2->next;
    }
    h1->next=h1->next->next;   // the one after the h1 need to be removed
    return head;
  }
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode * p;
    for(p = head; p != NULL; p = p->next) len++;
    if(len < n) return head;
    if(len == n) return head->next;
    p = head;
    for(int i = 0; i < len -n-1; i++ ) p = p->next;
    p->next = p->next->next;
    return head;      
  }
};
