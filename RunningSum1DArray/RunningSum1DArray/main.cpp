#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> result;
        int sum{ 0 };
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            result.push_back(sum);
        }
        return result;
    }
};


int main() {
    std::vector<int> vec{ 1,2,3,4 };
    Solution sol;

    std::vector<int> result = sol.runningSum(vec);

    for (auto elem : result) {
        std::cout << elem << ", ";
    }

    std::cout << "\n";
    return 0;
}