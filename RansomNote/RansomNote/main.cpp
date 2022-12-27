#include <iostream>
#include <string>
#include <algorithm>


class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::sort(magazine.begin(), magazine.end());
        std::sort(ransomNote.begin(), ransomNote.end());

        return (std::includes(magazine.begin(), magazine.end(), ransomNote.begin(), ransomNote.end()));
    }
};

int main() {
    std::string ransomNote{"aa"};
    std::string magazine{"aab"};
    Solution sol;
    bool result = sol.canConstruct(ransomNote, magazine);

    std::cout << "Does it include? " << std::boolalpha << result << std::endl;
    return 0;
}