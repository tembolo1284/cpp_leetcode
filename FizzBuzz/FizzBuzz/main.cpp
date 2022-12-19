#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;

        for (int i = 1; i <= n; i++) {
            if ((i % 3 == 0) && (i % 5 == 0)) {
                result.push_back("FizzBuzz");
            }
            else if (i % 5 == 0) {
                result.push_back("Buzz");
            }
            else if (i % 3 == 0) {
                result.push_back("Fizz");
            }
            else {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> result = sol.fizzBuzz(3);

    for (auto elem : result) {
        std::cout << elem << ", ";
    }

    return 0;
}