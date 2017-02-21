/*You are given two non-empty linked lists representing two non-negative integers.
  The digits are stored in reverse order and each of their nodes contain a single digit. 
  Add the two numbers and return it as a linked list.
  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode *L = NULL;
    ListNode *p, *node;
    ListNode *tmp1 = l1;
    ListNode *tmp2 = l2;
    int carryBit = 0;
    while(true)
      {
	if(tmp1 == NULL || tmp2 == NULL)
	  {
	    break;
	  }
	carryBit += tmp1->val+tmp2->val;
	node = new ListNode(carryBit%10);
	carryBit /= 10;
	if(p == NULL)
	  {
	    p = node;
	    L = p;
	  }
	else
	  {
	    p->next = node;
	    p = p->next;
	  }
	tmp1 = tmp1->next;
	tmp2 = tmp2->next;
      }

    ListNode *rl = tmp1 == NULL?tmp2:tmp1;
    while(rl != NULL)
      {
	carryBit += rl->val;
	node = new ListNode(carryBit%10);
	carryBit /= 10;
	if(p == NULL)
	  {
	    p = node;
	    L = p;
	  }
	else
	  {
	    p->next = node;
	    p = p->next;
	  }
	rl = rl->next;
      }

    if(carryBit != 0)
      {
	node = new ListNode(carryBit);
	p->next = node;
      }

    return L;
  }
};

int main()
{
  cout << "Hello world!" << endl;
  ListNode* l1 = new ListNode(2);
  ListNode* node = new ListNode(4);
  l1->next = node;
  node = new ListNode(3);
  l1->next->next = node;
  ListNode*l2 = new ListNode(5);
  node = new ListNode(6);
  l2->next = node;
  node = new ListNode(4);
  l2->next->next = node;

  Solution* sl = new Solution;
  ListNode* L = sl->addTwoNumbers(l1,l2);
  while(L != NULL)
    {
      cout<<L->val<<" ";
      L = L->next;
    }
  return 0;
}
