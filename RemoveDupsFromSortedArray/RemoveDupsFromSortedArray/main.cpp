#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int count{ 0 };
        int size = nums.size();
        for (int i = 0; i < size-1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                count += 1;
                size -= 1;
            }
        }

        std::cout << "Resulting vector: ";
        for (auto elem : nums) {
            std::cout << elem << ", ";
        }
        std::cout << "\n";
        return count;
    }
};


int main() {
    std::vector<int> vec{1, 1, 2};
    Solution sol;
    std::cout << "We have removed " << sol.removeDuplicates(vec) << " elements." << std::endl;

    return 0;
}