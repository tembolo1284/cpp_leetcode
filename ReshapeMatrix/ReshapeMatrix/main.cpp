#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        std::queue<int> temp;
        std::vector<std::vector<int>> result;
        std::vector<int> tempColVec;
        int currRowSize = mat.size();
        int currColSize = mat[0].size();

        if ((r * c) != (currRowSize * currColSize)) {
            return mat;
        }

        for (int i = 0; i < currRowSize; i++) {
            for (int j = 0; j < currColSize; j++) {
                temp.push(mat[i][j]);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                tempColVec.push_back(temp.front());
                temp.pop();
            }
            result.push_back(tempColVec);
            tempColVec.clear();
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> vec1{ {1,2},{3,4}};
    int r = 2;
    int c = 6;

    std::vector<std::vector<int>> result = sol.matrixReshape(vec1, r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
        
    return 0;
}