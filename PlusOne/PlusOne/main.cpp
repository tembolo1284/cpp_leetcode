#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;

        for (int i = n; i >= 0; --i) { 

            if (digits[i] == 9) {
                digits[i] = 0;
            } else {  
                digits[i] += 1;
                return digits;
            }
        }
      
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


int main() {
    Solution sol;
    std::vector<int> vec1{ 9,9,9 };
    std::vector<int> vec2{ 4,9,9 };
    auto result1 = sol.plusOne(vec1);
    auto result2 = sol.plusOne(vec2);

    for (auto elem : result1) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";
    for (auto elem : result2) {
        std::cout << elem << ", ";
    }

return 0;
}