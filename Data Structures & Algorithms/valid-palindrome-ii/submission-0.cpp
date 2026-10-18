class Solution {
   public:
    bool palindrom(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;

            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return palindrom(s, i + 1, j) || palindrom(s, i, j - 1);
            }

            i++;
            j--;
        }

        return true;
    }
};