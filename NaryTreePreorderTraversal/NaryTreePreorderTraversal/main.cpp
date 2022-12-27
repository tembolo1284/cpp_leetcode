#include <iostream>
#include <vector>
#include <stack>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void travel(Node* root, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        for (Node* child : root->children) {
            travel(child, result);
        }
    }
public:
    std::vector<int> preorder_recursion(Node* root) {
        std::vector<int> result;
        travel(root, result);
        return result;
    }

    std::vector<int> preorder_iterative(Node* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }

        std::stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            for (int i = cur->children.size() - 1; i >= 0; i--) {
                if (cur->children[i] != nullptr) {
                    stk.push(cur->children[i]);
                }
            }
        }
        return result;
    }
};

int main() {
    Node n5(5);
    Node n6(6);
    
    std::vector<Node*> children1;
    children1.push_back(&n5);
    children1.push_back(&n6);
   
    Node n3(3, children1);

    Node n2(2);
    Node n4(4);
    std::vector<Node*> children2;
    children2.push_back(&n3);
    children2.push_back(&n2);
    children2.push_back(&n4);
    Node n1(1, children2);

    Solution sol;
    std::vector<int> result = sol.preorder_iterative(&n1);

    std::cout << "Vector from iteration: ";
    for (auto elem : result) {
        std::cout << elem << ", " ;
    }

    std::vector<int> result1 = sol.preorder_recursion(&n1);

    std::cout << "\nVector from recursion: ";
    for (auto elem : result1) {
        std::cout << elem << ", ";
    }
    return 0;
}