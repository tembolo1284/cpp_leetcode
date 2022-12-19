#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        
        for (int i = m; i < (m + n); i++) {
            nums1.at(i) = nums2[i - m];
        }

        std::sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution sol;
    std::vector<int> vec1{1,2,3,0,0,0};
    std::vector<int> vec2{2,5,6};
    int m = 3;
    int n = 3;
    sol.merge(vec1, m, vec2, n);

    std::cout << "Values of vec1 after merge: ";
    for (auto elem : vec1) {
        std::cout << elem << ", ";
    }

    return 0;
}