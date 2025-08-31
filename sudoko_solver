// sudoku_solver.cpp
// Problem: Solve Sudoku Puzzle
// Link: https://leetcode.com/problems/sudoku-solver/
// Difficulty: Hard
// Tags: Backtracking

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == ch || board[i][c] == ch) return false;
        if (board[3*(r/3) + i/3][3*(c/3) + i%3] == ch) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, r, c, ch)) {
                        board[r][c] = ch;
                        if (solve(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solve(board);
    cout << "Solved Sudoku:\n";
    for (auto &row : board) {
        for (char c : row) cout << c << " ";
        cout << "\n";
    }
    return 0;
}
