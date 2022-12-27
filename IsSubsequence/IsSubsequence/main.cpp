#include <iostream>
#include <string>
#include <algorithm>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int n = s.length(), m = t.length();
        int j = 0;
        for (int i = 0; i < m and j < n; i++)
            if (s[j] == t[i])
                j++;
        return (j == n);
    }
};

int main() {
    std::string s{"axc"};
    std::string t{"ahbgdc"};
    Solution sol;

    bool result = sol.isSubsequence(s, t);

    std::cout << "isSequence? " << std::boolalpha << result << std::endl;


    return 0;
}