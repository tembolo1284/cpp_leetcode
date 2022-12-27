#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

std::vector<std::vector<int>> ret;

class Solution {
public:
    void buildVector(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (ret.size() == depth) {
            ret.push_back(std::vector<int>());
        }

        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }

std::vector<std::vector<int> > levelOrder(TreeNode* root) {
    buildVector(root, 0);
    return ret;
}

};

int main() {
    TreeNode n15(15);
    TreeNode n7(7);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9);
    TreeNode n3(3, &n9, &n20);
    Solution sol;

    std::vector<std::vector<int>> result = sol.levelOrder(&n3);

    int level = result.size();

    std::cout << "[";
    for (int i = 0; i < level; i++) {
        std::cout << "[";
        for (auto elem : result[i]) {
            std::cout << elem << ", ";
        }
        std::cout << "] ";
    }
    std::cout << "]";
    std::cout << "\n";


return 0;
}