#include <iostream>

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return helper(root->left, min, root->val) &&
            helper(root->right, root->val, max);
    }
};

int main() {
    TreeNode n6(6);
    TreeNode n3(3);
    TreeNode n4(4, &n6, &n3);
    TreeNode n1(1);
    TreeNode n5(5, &n1, &n4);

    TreeNode n2(2, &n1, &n3);
    Solution sol;
    bool result = sol.isValidBST(&n5);
    bool result1 = sol.isValidBST(&n2);
    std::cout << "Is the Tree valid? " << std::boolalpha << result << std::endl;
    std::cout << "Is the Tree valid? " << result1 << std::endl;
    return 0;
}