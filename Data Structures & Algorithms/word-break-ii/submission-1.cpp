class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return wordBreakHelper(s, 0, dict);
    }

   private:
    vector<string> wordBreakHelper(string s, int start, unordered_set<string>& dict) {
        vector<string> validSubstr;

        // Base case
        if (start == s.length()) {
            validSubstr.push_back("");
            return validSubstr;
        }

        // Try every possible prefix
        for (int end = start + 1; end <= s.length(); end++) {
            string prefix = s.substr(start, end - start);

            // If prefix exists in dictionary
            if (dict.count(prefix)) {
                vector<string> suffixes = wordBreakHelper(s, end, dict);

                for (string suffix : suffixes) {
                    validSubstr.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }

        return validSubstr;
    }
};