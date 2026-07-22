class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxi = 0;
        unordered_map<char, int> mpp;

        for (int right = 0; right < n; right++) {
            if (mpp.find(s[right]) != mpp.end()) {
                if (mpp[s[right]] >= left) {
                    left = mpp[s[right]] + 1;
                }
            }

            mpp[s[right]] = right;
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
