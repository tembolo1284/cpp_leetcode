#include <iostream>
#include <string>
#include <map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::map<char, int> map;
        size_t size = s.length();
        for (int i = 0; i < size; i++) {
            map[s[i]]++;
        }
                
        for (int i = 0; i < size;i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::string s1{"leetcode"};
    std::string s2{"aabb"};
    std::string s3{ "loveleetcode" };
    Solution sol;

    int result1 = sol.firstUniqChar(s1);
    int result2 = sol.firstUniqChar(s2);
    int result3 = sol.firstUniqChar(s3);

    std::cout << "first result: " << result1 << std::endl;
    std::cout << "second result: " << result2 << std::endl;
    std::cout << "third result: " << result3 << std::endl;
    return 0;
}