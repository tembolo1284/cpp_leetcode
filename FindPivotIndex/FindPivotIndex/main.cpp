#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int size = nums.size();
        int rightSum{ 0 };
        int leftSum{ 0 };

        for (auto elems : nums) {
            rightSum += elems;
        }

        for (int i = 0; i < size; i++) {
            leftSum += nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            rightSum -= nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> vec{1,7,3,6,5,6};
    std::vector<int> vec1{ 1,2,3 };
    int result = sol.pivotIndex(vec1);
    std::cout << result;
    return 0;
}