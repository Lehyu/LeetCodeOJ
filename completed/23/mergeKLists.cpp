/*
  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return NULL;
    if(lists.size() == 1) return lists[0];
    ListNode head(0);
    ListNode* l1 = lists[0];
    for(int i = 1; i < lists.size(); i++) {
      ListNode tmp(0);
      ListNode *p = &tmp;
      ListNode *l2 = lists[i];
      while(l1 && l2) {
	bool flag = l1->val <= l2->val;
	int val = flag? l1:l2;
	p->next = new ListNode(val);
	flag?l1=l1->next:l2=l2->next;
	p = p->next;
      }
      p->next = l1 == NULL?l2:l1;
      l1 = tmp.next;
      head = tmp;
    }
    return head.next;
  }
};
