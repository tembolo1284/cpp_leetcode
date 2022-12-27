#include <iostream>

struct ListNode {
int val;
ListNode* next;
ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!(fast && fast->next)) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};

int main() {
    ListNode n4(-4);
    ListNode n0(0);
    ListNode n2(2);
    ListNode n3(3);
    n3.next = &n2;
    n2.next = &n0;
    n0.next = &n4;
    n4.next = &n2;

    
    ListNode n11(1);
    n11.next = nullptr;
    

    int count{ 0 };

    ListNode* ptr = &n3;
    while (count < 15) {
        std::cout << "[" << ptr->val << "] -> ";
        ptr = ptr->next;
        count += 1;
    }

    Solution sol;
    ListNode* result = sol.detectCycle(&n3);
    ListNode* result1 = sol.detectCycle(&n11);

    std::cout << result->val;
    std::cout << result1->val;
}