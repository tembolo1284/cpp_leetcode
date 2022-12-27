#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {	
		if (l1 == nullptr){
			return l2;
		}

		if (l2 == nullptr) {
			return l1;
		}

		if (l1->val <= l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

int main() {
    ListNode n41(4);
    ListNode n42(4);
    ListNode n2(2, &n41);
    ListNode n3(3, &n42);
    ListNode n11(1, &n2); //[1, 2, 4]
    ListNode n12(1, &n3); //[1, 3, 4]

    Solution sol;

    ListNode* result = sol.mergeTwoLists(&n11, &n12);

    do {
        std::cout << "[" << result->val << "] -> ";
        result = result->next;
    } while (result->next != nullptr);



    return 0;
}