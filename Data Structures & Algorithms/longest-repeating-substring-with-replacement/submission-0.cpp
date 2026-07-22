class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int l = 0;
        int maxfreq = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);
            // len - maxfreq = total changes
            while ((r - l + 1) - maxfreq > k) {
                mpp[s[l]]--;
                l++;
            }

            ans = max(ans, (r - l + 1));
        }

        return ans;
    }
};
