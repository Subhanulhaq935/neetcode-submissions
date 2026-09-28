class Solution {
   public:
    struct Node {
        Node* ch[26] = {};
        string* word = nullptr;
    };

    int m, n;
    vector<string> ans;

    void dfs(vector<vector<char>>& board, int i, int j, Node* node) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;

        // Already visited
        if (board[i][j] == '#') return;

        char c = board[i][j];

        if (!node->ch[c - 'a']) {
            return;
        }

        node = node->ch[c - 'a'];

        // Complete word mil gaya
        if (node->word != nullptr) {
            ans.push_back(*node->word);

            // Duplicate avoid
            node->word = nullptr;
        }

        // Visited mark
        board[i][j] = '#';

        // 4 directions
        dfs(board, i + 1, j, node);  // down
        dfs(board, i - 1, j, node);  // up
        dfs(board, i, j + 1, node);  // right
        dfs(board, i, j - 1, node);  // left

        // Backtracking
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        Node* root = new Node();
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];

            Node* node = root;

            for (int j = 0; j < w.length(); j++) {
                char c = w[j];

                int index = c - 'a';

                if (!node->ch[index]) {
                    node->ch[index] = new Node();
                }

                node = node->ch[index];
            }

            node->word = &words[i];
        }

        // Board ke har cell se DFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
