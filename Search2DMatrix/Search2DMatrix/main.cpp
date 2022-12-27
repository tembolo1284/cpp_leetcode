#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        bool isElem = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            if (matrix[i][cols- 1] == target) {
                isElem = true;
                return isElem;
            } else if (matrix[i][cols - 1] < target) {
                continue;
            } else {
                if (std::binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                    isElem = true;
                    return isElem;
                }
            }
        }
        return isElem;
    }
};


int main() {
    Solution sol;
    std::vector<std::vector<int>> vec{ {1,3,5,7},{10,11,16,20},{23,20,34,60} };
    int x = 35;

    bool result = sol.searchMatrix(vec, x);

    std::cout << "Matrix is: " << std::endl;
    int rows = vec.size();
    int cols = vec[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Is " << x << " in the matrix? " << std::boolalpha << result << std::endl;
    return 0;
}