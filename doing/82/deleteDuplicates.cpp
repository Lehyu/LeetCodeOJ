struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL){};
};

class Solutin{
public:
  ListNode* deleteDuplicates(ListNode* head){
    if(head == NULL) return head;
    ListNode *p = head;
    head->next = p;
    p = head;
    while(p->next != NULL){
      ListNode* q = p->next->next;
      for(; q != NULL && p->next->val == q->val; q = q->next);
      if(q != p->next->next)
	p->next = q;
      else{
	p = p->next;
      }
    }
    return head->next;
  }
};
