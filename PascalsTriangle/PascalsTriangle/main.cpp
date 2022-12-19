#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int> > generate(int numRows) {
        std::vector<std::vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};


int main() {
    Solution sol;
    int x =5;
    
    auto result = sol.generate(5);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}