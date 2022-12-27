#include <iostream>
#include <string>
#include <stack>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        if (s.empty()) {
            return true;
        }
        for (auto elem : s) {
            if (elem == '(' || elem == '[' || elem == '{') {
                st.push(elem);
            }
            else {
                if (st.empty() || (elem == '}' && st.top() != '{') || (elem == ']' && st.top() != '[') || (elem == ')' && st.top() != '(')) {
                    return false;
                }
                st.pop();
            }

             
        }
        return st.empty();
    }
};

int main() {
    std::string str1{ "()[]{}" };
    std::string str2{"(]"};
    Solution sol;

    bool result1 = sol.isValid(str1);
    bool result2 = sol.isValid(str2);

    std::cout << "Result1 is: " << std::boolalpha << result1 << std::endl;
    std::cout << "Result2 is: " << result2 << std::endl;
    return 0;
}