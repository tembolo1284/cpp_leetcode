#include <iostream>

struct ListNode {
int val;
ListNode* next;
ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptrA = headA, * ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};

int main() {
    ListNode c3(3);
    ListNode c2(2);
    ListNode c1(1);
    ListNode a2(2);
    ListNode a1(1);
    ListNode b3(3);
    ListNode b2(2);
    ListNode b1(1);
    c2.next = &c3;
    c1.next = &c2;
    a2.next = &c1;
    b3.next = &c1;
    a1.next = &a2;
    b2.next = &b3;
    b1.next = &b2;
    Solution sol;
    ListNode* result = sol.getIntersectionNode(&a1, &b1);

    std::cout << "Intersection node val: " << result->val;

}