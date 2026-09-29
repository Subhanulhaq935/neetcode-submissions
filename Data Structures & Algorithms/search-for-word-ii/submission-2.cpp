class Solution {
   public:
    struct Node {
        Node* ch[26] = {};
        string* word = nullptr;
    };

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n, vector<string>& ans,
             Node* node) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#') return;

        char c = board[i][j];

        if (!node->ch[c - 'a']) return;

        node = node->ch[c - 'a'];

        if (node->word != nullptr) {
            ans.push_back(*node->word);

            node->word = nullptr;
        }

        board[i][j] = '#';

        dfs(board, i, j + 1, m, n, ans, node);
        dfs(board, i + 1, j, m, n, ans, node);
        dfs(board, i, j - 1, m, n, ans, node);
        dfs(board, i - 1, j, m, n, ans, node);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        vector<string> ans;

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

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, m, n, ans, root);
            }
        }

        return ans;
    }
};
