#include <iostream>
#include <vector>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int low = 0, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> vec{-1,0,3,5,9,12};
    int target = 9;
    Solution sol;
    int result = sol.search(vec, target);
    std::cout << result;
    return 0;
}