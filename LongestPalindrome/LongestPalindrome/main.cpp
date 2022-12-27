#include <iostream>
#include <string>
#include <map>
#include <functional>
class Solution {
public:
    int longestPalindrome(std::string s) {
        std::map<char, int> map;
        for (auto elem : s) {
            map[elem]++;
        }
        int OddGroup = 0;
        for (int i = 0; i < map.size(); i++) {
            if (map[i] & 1) {
                OddGroup += 1;
            }
        }
        return s.size() - OddGroup + (OddGroup > 0);
    }
};

int main() {
    std::string s1{"abccccdd"};

    Solution sol;
    int result = sol.longestPalindrome(s1);
    std::cout << result;

    return 0;
}