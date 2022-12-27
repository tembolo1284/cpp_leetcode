#include <iostream>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int rows[9][9] = { 0 };
        int cols[9][9] = { 0 };
        int blocks[3][3][9] = { 0 };

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') { 
                    continue; 
                }
                int num = board[r][c] - '1';
                if (cols[num][c]++ || rows[r][num]++ || blocks[r / 3][c / 3][num]++) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    std::vector<std::vector<char>> board1{ {'8','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, 
                                          {'.','9','8','.','.','.','.','6','.'}, {'8','.','.','.','6','.','.','.','3'}, 
                                          {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'},
                                          {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, 
                                          {'.','.','.','.','8','.','.','7','9'} 
                                          };

    std::vector<std::vector<char>> board2{ {'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'},
                                          {'.','9','8','.','.','.','.','6','.'}, {'8','.','.','.','6','.','.','.','3'},
                                          {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'},
                                          {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'},
                                          {'.','.','.','.','8','.','.','7','9'}
                                          };
    Solution sol;

    bool result1 = sol.isValidSudoku(board1);
    bool result2 = sol.isValidSudoku(board2);

    std::cout << "Is board1 a valid sudoku? " << std::boolalpha << result1 << std::endl;
    std::cout << "Is board2 a valid sudoku? " << std::boolalpha << result2 << std::endl;

    
    return 0;
}