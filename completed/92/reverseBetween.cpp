struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};
class Solution{
  // convert to Reverse Linked List.
  ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode* head0 = new ListNode(0);
    head0->next = head;
    ListNode* p = head0;
    for(int i = 0; i < m-1; i++)
      p = p->next;
    ListNode* cur = p->next;
    for(int i = 0; i < n-m; i++){
      ListNode * tp = cur->next;
      cur->next = tp->next;
      tp->next = p->next;
      p->next = tp;
    }
    return head0->next;
  }
  ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode head0(0);
    head0.next = head;
    ListNode* p = &head0, *pm=NULL, *rp=NULL, *tail=NULL;
    int k = 0;
    for(; k < m-1; k++) p = p->next;
    pm = p;
    p = p->next;
    for(; k < n; k++){
      ListNode* tp = p;
      p = p->next;
      if(!rp) {
	rp = tp;
	tail = rp;
      }
      else{
	tp->next = rp;
	rp = tp;
      }

    }
    pm->next = rp;
    tail->next = p;
    return head0.next;
  }
  // wrong solution, which will dead loop
  ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode head0(0);
    head0.next = head;
    ListNode* p = &head0, *pm, *pn, *rp, *tail;
    int k = 0;
    for(; k < m-1; k++) p = p->next;
    pm = p;
    for(; k < n; k++){
      ListNode* tp = p->next;
      if(!rp) {
	rp = tp;
	tail = rp;
      }
      else{
	tp->next = rp;
	rp = tp;
      }
      p = p->next;
    }
    pm->next = rp;
    tail->next = p->next;
    return head0.next;
  }
};
