#include <vector>
#include <iostream>
#include <map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, int> map;

        for (auto elem : nums) {
            if (map[elem]) {
                return true;
            }
            map[elem]++;
        }
        return false;
    }
};


int main() {
    std::vector<int> vec{ 1, 2, 2 ,3 };

    Solution sol;
    auto result = sol.containsDuplicate(vec);
    std::cout << "Does vec contain a duplicate? " << std::boolalpha << result << std::endl;
    
    return 0;
}