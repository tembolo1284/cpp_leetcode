#include <iostream>
class Solution {
public:
    int fib(int n) {
        int result{ 0 };

        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else {
            result = fib(n - 1) + fib(n - 2);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int input = 3;
    int result = sol.fib(input);
    std::cout << result << std::endl;
    return 0;
}