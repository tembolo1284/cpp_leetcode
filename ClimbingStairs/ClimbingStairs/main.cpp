#include <iostream>
#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> result;
        result.push_back(0);
        result.push_back(1);
        result.push_back(2);

        for (int i = 3; i <= n; i++) {
            result.push_back(result[i - 1] + result[i - 2]);
        }
        return result[n];
    }
};


int main() {
    Solution sol;
    int result = sol.climbStairs(45);
    std::cout << result << std::endl;
    return 0;
}