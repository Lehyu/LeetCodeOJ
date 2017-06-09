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
    while(p != NULL){
      ListNode* q = p->next;
      for(; q != NULL && p->val == q->val; q = q->next);
      if(q != p->next) p->next = q;
      else p = p->next;
    }
    return head;
  }
};
