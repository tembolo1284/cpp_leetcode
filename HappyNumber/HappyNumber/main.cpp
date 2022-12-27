#include <iostream>
#include <string>
#include <map>
class Solution {
public:
    bool isHappy(int n) {
        std::map<int, int> map;

        while (n != 1) {
            if (map[n] == 0) {
                map[n]++;
            }
            else {
                return false;
            }

            int sum = 0;
            while (n != 0) {
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            n = sum;
        }
        return true;
    }
};


int main() {

    Solution sol;
    int n = 19;
    bool result = sol.isHappy(n);

    std::cout << "Is " << n << " a happy number? " << std::boolalpha << result << std::endl;


    return 0;
}