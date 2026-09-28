class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, m, n, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int m, int n, int index) {
        if (index == word.length()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }

        // Character match nahi karta
        if (board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        // 4 directions
        bool found = dfs(board, word, i, j + 1, m , n, index + 1) ||  // right
                     dfs(board, word, i + 1, j, m , n, index + 1) ||  // down
                     dfs(board, word, i, j - 1, m , n, index + 1) ||  // left
                     dfs(board, word, i - 1, j, m , n , index + 1);    // up

        // Backtrack: original character wapas
        board[i][j] = temp;

        return found;
    }
};
