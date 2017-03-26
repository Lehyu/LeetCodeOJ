struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};
class Solution{
  ListNode* reverseBetween(ListNode* head, int m, int n){
    if(m == n) return head;
    ListNode* p = head, *q = head, *k, temp;
    for(int i = 1; i < m; i++) p = p->next;
    k = p;
    p = p->next;
    q = p;
    for(int i = m; i < q; i++){
      p = p->next;
      temp = p->next;
      p->next = q;
      q = p;
      p = temp;
    }
    temp = p->next;
    k->next = p;
    for(int i = 1; i < (n-m); i++){
      p = p->next;
    }
    p->next = temp;
    return head;
  }
};
