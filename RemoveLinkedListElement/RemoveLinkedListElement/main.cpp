#include <iostream>


//Definition for singly - linked list.
struct ListNode {
int val;
ListNode* next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode nodeNull();
    ListNode n61(6);
    ListNode n5(5, &n61);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n62(6, &n3);
    ListNode n2(2, &n62);
    ListNode n1(1, &n2);

    ListNode* temp = &n1;

    std::cout << "linked list before removal: ";
    while (temp != nullptr) {
        std::cout << "[" << temp->val << "] -> ";
        temp = temp->next;
    }

    Solution sol;
    ListNode* result = sol.removeElements(&n1, 6);

    

    std::cout << "\nlinked list after removal: ";
    while (result != nullptr) {
        std::cout << "[" << result->val << "] -> ";
        result = result->next;
    }
    std::cout << "\n";

    return 0;
}