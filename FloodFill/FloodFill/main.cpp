#include <iostream>
#include <vector>

class Solution {
public:

    void dfs(std::vector<std::vector<int>>& image, int i, int j, int val, int newColor)   {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != val) {
            return;
        }
        image[i][j] = newColor;
        dfs(image, i - 1, j, val, newColor);
        dfs(image, i + 1, j, val, newColor);
        dfs(image, i, j - 1, val, newColor);
        dfs(image, i, j + 1, val, newColor);
    }

    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
        int val = image[sr][sc];
        dfs(image, sr, sc, val, newColor);
        return image;
    }
};

int main() {
    std::vector<int> row1{ 1,1,1,1 };
    std::vector<int> row2{ 1,1,0,2 };
    std::vector<int> row3{ 1,0,1,1 };
    std::vector<std::vector<int>> image;
    image.push_back(row1);
    image.push_back(row2);
    image.push_back(row3);
    int rows = image.size();
    int cols = image[0].size();
    Solution sol;
    std::cout << "Before Flood Fill:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << image[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::vector<std::vector<int>> result = sol.floodFill(image, 1, 1, 3);

    std::cout << "After Flood Fill:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}