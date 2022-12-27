#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev{ nullptr };
        ListNode* next{ nullptr };

        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


int main() {
    Solution sol;
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    ListNode* temp1 = &n1;
    std::cout << "Original Linked List: ";
    do {
        std::cout << "[" << temp1->val << "] -> ";
        temp1 = temp1->next;
    } while (temp1 != nullptr);

    ListNode* result = sol.reverseList(&n1);
    std::cout << "\nReversed Linked List: ";

    do {
        std::cout << "[" << result->val << "] -> ";
        result = result->next;
    } while (result != nullptr);

    return 0;
}