/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 纯迭代
    ListNode* reverseList(ListNode* head) {
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
    // 更类似于递归
    ListNode* reverseList1(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *next = nullptr, *p = head, *q = nullptr;
        while (p) {
            q = p->next;
            p->next = next;
            next = p;
            p = q;
        }
        return next;
    }
    // 递归
    ListNode* reverseList2(ListNode *head) {
        if (head == nullptr) return head;
        return reverseList_helper(head, nullptr);
    }
    ListNode* reverseList_helper(ListNode *curr, ListNode *next) {
        if (curr == nullptr) return next;
        ListNode *tmp = curr->next;
        curr->next = next;
        return reverseList_helper(tmp, curr);
    }
    void print(ListNode *p) {
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};
