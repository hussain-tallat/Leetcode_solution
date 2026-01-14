#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            vector<bool> used(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if (used[num]) return false;
                used[num] = true;
            }
        }

        for (int j = 0; j < 9; j++) {
            vector<bool> used(9, false);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if (used[num]) return false;
                used[num] = true;
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<bool> used(9, false);
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] == '.') continue;
                        int num = board[i][j] - '1';
                        if (used[num]) return false;
                        used[num] = true;
                    }
                }
            }
        }

        return true;
    }
};
