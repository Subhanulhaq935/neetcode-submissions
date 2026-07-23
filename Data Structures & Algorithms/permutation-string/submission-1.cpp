class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freq1(26, 0);

        // Store frequency of s1
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }

        int windowSize = s1.size();

        for (int i = 0; i < s2.size(); i++) {

            int windowIdx = 0;
            int idx = i;

            vector<int> freq2(26, 0);

            while (windowIdx < windowSize && idx < s2.size()) {
                freq2[s2[idx] - 'a']++;
                windowIdx++;
                idx++;
            }

            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};