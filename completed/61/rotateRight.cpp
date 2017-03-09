struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* rotateRight(ListNode *head, int k) {
    if(head == NULL) return head;
    int len = 0;
    ListNode* p = head;
    for(; p!=NULL; p=p->next, len++);
    k %= len;
    p->next = head;
    for(int i = 0; i < len-k; i++, p = p->next);
    head = p->next;
    p->next = NULL;
    return head;
  }
  ListNode* rotateRight(ListNode *head, int k) {
    if(head == NULL) return head;
    int len = 0;    
    ListNode* p = head, *q = head;
    for(; p != NULL; p = p->next, len++);
    k = k%len;
    for(int i = 0; i < k && q != NULL; i++) q = q->next;
    for(p = head; q->next!=NULL; q=q->next) p = p->next;
    q->next = head;
    head = p->next;
    p->next = NULL;
    return head;
  }
};
