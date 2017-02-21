/*
*/
class Solution{
public:
  ListNode* swapPairs(ListNode* head){
    ListNode node(0);
    node.next = head;
    ListNode* p = &node;
    while(p!=NULL && p->next !=NULL && p->next->next != NULL){
      ListNode* tmp = p->next;
      p->next = p->next->next;
      tmp->next = p->next->next;
      p->next->next = tmp;
      p = p->next->next;
    }
    return node.next;
  }
};
