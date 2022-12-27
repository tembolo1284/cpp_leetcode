
// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count{ 1 };
        while (temp->next != nullptr) {
            temp = temp->next;
            count++;
        }

        int mid = (count / 2) + 1;
      
        count = 1;
        temp = head;
        while (temp->next != nullptr) {
            if (mid == count) {
                return temp;
            }
            temp = temp->next;
            count++;
        }
        return temp;
    }
};

int main() {
    Solution sol;
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    auto result = sol.middleNode(&n1);
    //ListNode* temp = result;

    return 0;
}