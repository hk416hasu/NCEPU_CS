#include <iostream>

using std::cin, std::cout, std::endl;

struct ListNode {
  int val;
  struct ListNode *next;

  ListNode(int x = 0, struct ListNode *ptr = nullptr) : val(x), next(ptr) {}
};

ListNode* split(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *tmp = slow->next;
  slow->next = nullptr;
  return tmp;
}

ListNode* mergeTwo(ListNode *left, ListNode *right) {
  ListNode dummy(0);
  ListNode *tail = &dummy;

  ListNode *p = left, *q = right;
  while (p && q) {
    if (p->val < q->val) {
      tail->next = p;
      p = p->next;
    } else {
      tail->next = q;
      q = q->next;
    }
    tail = tail->next;
  }
  tail->next = p ? p : q;
  return dummy.next;
}

ListNode* mergeSort(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode *left = head;
  ListNode *right = split(head);

  left = mergeSort(left);
  right = mergeSort(right);

  return mergeTwo(left, right);
}

int main() {

  int num = 0;
  ListNode dummy(0);
  ListNode *tail = &dummy;

  while (cin >> num) {
    tail->next = new ListNode(num);
    tail = tail->next;
  }

  ListNode *p = mergeSort(dummy.next);
  // ListNode *p = dummy.next;
  while (p != nullptr) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
