#include <iostream>
#include <string>
#include <map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::map<char, int> map;

        for (auto elem : s) {
            map[elem]++;
        }

        for (auto elem : t) {
            map[elem]--;
        }
        int size = map.size();
        for (auto elems : map) {
            if (elems.second != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::string s1{"anagram"};
    std::string s2{"nagaram"};
    std::string s3{ "rat" };
    std::string s4{ "car" };
    Solution sol;

    bool result = sol.isAnagram(s1, s2);
    bool result1 = sol.isAnagram(s3, s4);

    std::cout << "Is anagram? " << std::boolalpha << result << std::endl;
    std::cout << "Is anagram? " << std::boolalpha << result1 << std::endl;

    return 0;
}