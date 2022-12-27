#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = std::min(p->val, q->val);
        int large = std::max(p->val, q->val);
        while (root != nullptr) {
            if (root->val > large) // p, q belong to the left subtree
                root = root->left;
            else if (root->val < small) // p, q belong to the right subtree
                root = root->right;
            else // Now, small <= root.val <= large -> This root is the LCA between p and q
                return root;
        }
        return nullptr;
    }
};

int main() {    
    TreeNode n5(5);
    TreeNode n3(3);
    TreeNode n4(4);
    n4.left = &n3;
    n4.right = &n5;
    TreeNode n0(0);
    TreeNode n2(2);
    n2.left = &n0;
    n2.right = &n4;
    TreeNode n7(7);
    TreeNode n9(9);
    TreeNode n8(8);
    n8.left = &n7;
    n8.right = &n9;
    TreeNode n6(6);
    n6.left = &n2;
    n6.right = &n8;
    Solution sol;
    TreeNode* result = sol.lowestCommonAncestor(&n6, &n2, &n4);
    std::cout << result->val << std::endl;


    return 0;
}