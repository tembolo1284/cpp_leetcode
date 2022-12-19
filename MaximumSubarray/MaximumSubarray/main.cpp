#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum{ 0 };
        for (auto n : nums) {
            sum = std::max(n, sum + n);
            max_sum = std::max(max_sum, sum);
        }
        return max_sum;
    }
};


int main() {
    std::vector<int> vec{ 1, -2, 3, -5, 2, 1,11, -3 };
    Solution sol;
    int result = sol.maxSubArray(vec);

    std::cout << "Max subarray is: " << result << std::endl;
    

    return 0;
}