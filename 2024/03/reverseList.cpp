#include <iostream>

#define ElemType int
typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkedList;

// 创建单链表
LinkedList CreateLList(LinkedList &L) {
    L = new LNode; L->data = 0; L->next = nullptr;
    LNode *pre = L, *tmp;
    for (int i(1); i <= 6; i++) {
        tmp = new LNode;
        tmp->data = i;
        pre->next = tmp;
        tmp->next = nullptr;
        pre = pre->next;
    }
    return L;
}
// 打印单链表
void PrintList(LinkedList L) {
    LNode *curr = L;
    printf("the List is: ");
    while (curr != nullptr) {
        std::cout<<curr->data<<" ";
        curr = curr->next;
    }
    printf("\n");
}


/*****************************************反转单链表（递归）*************************************************/
// 要宏观理解！！！

// 这个写的最好，最直观，且原地工作 + 复用栈帧

/**
 * @param: *curr是当前单链表表头结点，*pre是*curr的前一个结点
*/
LinkedList reverseList(LNode *curr, LNode *pre = nullptr) {
    // 最小子问题：若当前链表头结点指针为空，则返回pre指针即可
    if (curr == nullptr) {
        return pre;
    }

    // 当前操作：反转curr与pre
    LNode *next = curr->next;   // 先保存一下curr->next, 它是待会下一次反转的头结点
    curr->next = pre;

    return reverseList(next, curr);    // 向后递推
}


LNode* reverseList_1(LinkedList L) {
    // 1 如果链表为空或只包含头结点，无需反转，直接返回
    // 2 是递归结束条件：当“递”到最后一个结点时，开始“归”
    if (L == nullptr || L->next == nullptr) {
        return L;
    }
    // 宏观理解：reverseList(L->next)反转 L->next 结点以及其后的链表，返回已反转好的链表的头结点。
    LNode *revListHead = reverseList_1(L->next);

    // 把当前结点插入到反转链表末尾
    L->next->next = L;  // L->next指向的是已反转链表的最后一个节点，可以的 你可以画图试试
    L->next = nullptr;  // 因为当前节点L已经放到已反转链表的末尾了，所以得把它的next置空    // 如果不置空，原链表头俩元素会互为next

    return revListHead; // ！！！rev在归的过程中是不变的，始终指向“已反转链表的新头结点，即原链表的尾结点”，不这么干的话，头结点就丢失了
}

LNode* reverseList_1_1(LinkedList L, LNode *pre = nullptr) {

    if (L->next == nullptr) { return L; }
    
    LNode *rev = reverseList_1_1(L->next, L);
    L->next->next = L;
    // rev->next = L 这么写是错的
    L->next = pre;

    return rev;
}


LNode* reverseList_2(LinkedList L, LNode *pre = nullptr) {

    if (L->next == nullptr) { return L; }
    
    LNode *rev = reverseList_2(L->next, L);
    L->next->next = L;
    L->next = pre;

    return rev;
}


LinkedList reverseList_3(LinkedList L, LNode *pre = nullptr) {
    if (L->next == nullptr) {
        L->next = pre;
        return L;
    }
    LinkedList next = L->next;
    L->next = pre;
    return reverseList_3(next, L);
}

LinkedList reverseList_leetcode0(LNode *curr, LNode *pre = nullptr) {
    if (!curr) {
        return pre;
    }
    LNode *next = curr->next;
    curr->next = pre;
    return reverseList_leetcode0(next, curr);
}


// 递归反转单链表大体上两种思路：
// 1. 顺序逆置，从头开始，每次逆置curr和pre，再递归的对后续链表进行逆置（尾递归）；
// 2. 先递到链表尾，即找到反转后链表的表头（revListHead），revListHead在归的时候不改变，只改变指针连接，记得置空指针。

int main() {

    LinkedList L;
    CreateLList(L);
    PrintList(L);

    L = reverseList_1(L);
    PrintList(L);


    system("pause");
    return 0;
}