class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> word;

        for (string w : wordList) {
            word.insert(w);
        }

        if (!word.count(endWord)) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int cnt = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                string current = q.front();
                q.pop();

                for (int j = 0; j < current.length(); j++) {

                    char original = current[j];

                    for (char c = 'a'; c <= 'z'; c++) {

                        current[j] = c;

                        if (current == endWord) {
                            return cnt + 1;
                        }

                        if (word.count(current)) {

                            q.push(current);

                            word.erase(current);
                        }
                    }

                    current[j] = original;
                }
            }

            cnt++;
        }

        return 0;
    }
};