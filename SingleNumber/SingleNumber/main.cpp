#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::map<int, int> map;

        for (auto elem : nums) {
            map[elem]++;
        }

        for (auto elem : nums) {
            if (map[elem] == 1) {
                return elem;
            }
        }
    }
};

int main() {
    std::vector<int> vec{4,1,2,1,2};
    Solution sol;
    int result = sol.singleNumber(vec);
    std::cout << "result: " << result;
}