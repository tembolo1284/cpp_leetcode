#include <iostream>
#include <vector>

class Solution {
public:
    void dfs(int i, int j, std::vector<std::vector<int>>& visited, std::vector<std::vector<char>>& grid, int rows, int cols) {
        if (i < 0 || j < 0 || i >= rows || j >= cols) {
            return;
        }
        if (visited[i][j] == 1) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        if (!visited[i][j]) {
            visited[i][j] = 1;
            dfs(i + 1, j, visited, grid, rows, cols);
            dfs(i - 1, j, visited, grid, rows, cols);
            dfs(i, j + 1, visited, grid, rows, cols);
            dfs(i, j - 1, visited, grid, rows, cols);   
        }
    }
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, visited, grid, rows, cols);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    std::vector<char> vec1{ '1','1','0','0','0' };
    std::vector<char> vec2{ '1','1','0','1','0' };
    std::vector<char> vec3{ '1','0','0','0','0' };
    std::vector<char> vec4{ '0','1','0','1','1' };
    std::vector<std::vector<char>> grid;
    grid.push_back(vec1);
    grid.push_back(vec2);
    grid.push_back(vec3);
    grid.push_back(vec4);
    Solution sol;
    int rows = grid.size();
    int cols = grid[0].size();
    std::cout << "Grid:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Number of islands: " << sol.numIslands(grid);
   

    return 0;
}