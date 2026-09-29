class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }

            i--;
            j--;
        }

        // Upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }

            i--;
            j++;
        }

        return true;
    }


    void solve(vector<string>& board, int row, int n, int& count) {

        // All queens placed
        if (row == n) {
            count++;
            return;
        }

        // Try every column
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Go to next row
                solve(board, row + 1, n, count);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }


    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        int count = 0;

        solve(board, 0, n, count);

        return count;
    }
};