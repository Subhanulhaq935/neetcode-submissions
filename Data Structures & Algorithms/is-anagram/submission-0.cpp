class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        unordered_map<char , int>freq1;
        unordered_map<char , int>freq2;

        for(char i:s)
        {
            freq1[i]++;
        }

        for(char j:t)
        {
            freq2[j]++;
        }

        return freq1 == freq2;

    }
};
