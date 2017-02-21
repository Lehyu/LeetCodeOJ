/*

 */
class Solution{
public:
  // stack push 23ms
  ListNode* reverseKGroup(ListNode*head, int k){
    auto node = head;
    for(int i = 0; i < k; i++){
      if(!node) return head;
      node = node->next;
    }
    auto p = head;
    auto top = node, font = node;
    while(p != node){
      auto tmp = p->next;
      top = p;
      top->next = font;
      p = tmp;
      font = top;
    }
    font->next = reverseKGroup(node, k);
    return font;
  }
  // 75ms
  ListNode* reverseKGroup(ListNode*head, int k) {
    if(head == NULL || k==1) return head;
    int len = 0;
    ListNode node(0);
    node.next = head;
    for(ListNode *p = head; p != NULL; p=p->next, len++);
    ListNode* q = &node;
    while(len >= k) {
      for(int num = k; num >= 0; num--) {
	ListNode *p = q;
	int i = 1;
	while(p!=NULL && p->next!=NULL && p->next->next != NULL && i < num) {
	  ListNode *tmp = p->next;
	  p->next = p->next->next;
	  tmp->next = p->next->next;
	  p->next->next = tmp;
	  p = p->next;
	  i++;
	}
      }
      for(int i = 0; i < k && q != NULL; i++) q = q->next;
      len -= k;
    }
    return node.next;
  }
};
