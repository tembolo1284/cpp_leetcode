#include <iostream>
struct ListNode {
int val;
ListNode* next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* next{ nullptr };
        ListNode* prev{ nullptr };
        prev = head;
        next = head->next;
        while (next != nullptr) {
            if (next->val == prev->val) {
                prev->next = next->next;
                next = next->next;

            } else {
                prev = next;
                next = prev->next;
                
            }
        }
        return head;
    }
};

int main() {
    ListNode n32(3);
    ListNode n31(3, &n32);
    ListNode n2(2, &n31);
    ListNode n12(1, &n2);
    ListNode n11(1, &n12);

    Solution sol;
    ListNode* ptr = &n11;
    while (ptr != nullptr) {
        std::cout << "[" << ptr->val << "] ->";
        ptr = ptr->next;
    }
    ListNode* result = sol.deleteDuplicates(&n11);
    std::cout << "\n";
    while (result != nullptr) {
        std::cout << "[" << result->val << "] ->";
        result = result->next;
    }

return 0;
}