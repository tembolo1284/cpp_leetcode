#include <iostream>
#include <string>
#include <map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::map<char, int> smap;
        std::map<char, int> tmap;
        int size = s.length();        
        for (int i = 0; i < size; i++) {
            if (smap[s[i]] != tmap[t[i]]) {
                return false;
            }       
            smap[s[i]] = tmap[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    std::string s1{"egg"};
    std::string s2{"add"};
    std::string s3{"foo"};
    std::string s4{"bar"};
    Solution sol;

    bool result1 = sol.isIsomorphic(s1, s2);
    bool result2 = sol.isIsomorphic(s3, s4);

    std::cout << "result1 = " << std::boolalpha << result1 << std::endl;
    std::cout << "result2 = " << result2 << std::endl;
    return 0;
}