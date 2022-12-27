#include <iostream>
struct ListNode {
int val;
ListNode* next;
ListNode(int x) : val(x), next(nullptr) {}

};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while ((fast != nullptr) && (fast->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        } 
        
        return false;
    }
};

int main() {
    ListNode n4(-4);
    ListNode n0(0);
    ListNode n2(2);
    ListNode n3(3);
    n4.next = &n2;
    n0.next = &n4;
    n2.next = &n0;
    n3.next = &n2;
    Solution sol;

    bool result = sol.hasCycle(&n3);

    std::cout << std::boolalpha << result << std::endl;
    return 0;
}