#include <iostream>
#include <vector>
#include <map>
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        std::map<int, int> map;

        for (int i = 0; i < nums1.size(); i++) {
            map[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (map[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }

        return result;
    }
};


int main() {
    Solution sol;
    std::vector<int> nums1{ 4,9,5,4 };
    std::vector<int> nums2{9,4,9,8,4};
    std::vector<int> result = sol.intersect(nums1, nums2);

    for (auto elem : result) {
        std::cout << elem << ", ";
    }

    return 0;
}
