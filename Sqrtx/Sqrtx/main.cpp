#include <iostream>


class Solution {
public:
    int mySqrt(int x) {
        long root = x;
        while ((root * root) > x) {
            root = (root + (x / root)) / 2;
        }
        return root;
    }
};


int main() {
    Solution sol;
    int result = sol.mySqrt(2);

    std::cout << result << std::endl;
    return 0;
}