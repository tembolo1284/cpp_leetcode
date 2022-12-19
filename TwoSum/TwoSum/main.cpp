#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && (nums[i] + nums[j] == target)) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        std::cout << "No indices matched target." << std::endl;
        return result;
    }
};


int main() {
    std::vector<int> nums{2, 7, 11, 15};
    int target{ 9 };
    Solution sol;

    auto result = sol.twoSum(nums, target);
    std::cout << "elems of result: ";
    for (auto elem : result) {
        std::cout << elem << ", ";
    }


    return 0;
}