#include <iostream>

class ListNode {
public:
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {};
   ListNode(int x) : val(x), next(nullptr) {};
   ListNode(int x, ListNode *ptr) : val(x), next(ptr) {};
};

void print(ListNode *head) {
   while (head) {
      printf("%d ", head->val);
      head = head->next;
   }
   puts("");
}

ListNode* insertHead(int x, ListNode *head) {
   return new ListNode(x, head);
}
   
ListNode* reverseList(ListNode *head) {
   if (head == nullptr || head->next == nullptr) {
      return head;
   }
   ListNode dummy(0, head);
   ListNode *p = dummy.next, *q = nullptr;
   while (p->next) {
      q = p->next;
      p->next = p->next->next;
      q->next = dummy.next;
      dummy.next = q;
   }
   return dummy.next;
}

int main() {
   ListNode *p = nullptr;
   for (int i = 5; i > 0; i--) {
      p = insertHead(i, p);
   }
   print(p);
   print(reverseList(p));
   return 0;
}
