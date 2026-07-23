class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        // we can use the array to store the frequency but still i am going to use the map
        unordered_map<char, int> mp;
        for (int i = 0; i < s1.size(); i++) {  // This loop will store the frequency
            mp[s1[i]]++;
        }

        int windsize = s1.size();

        for (int i = 0; i < s2.length(); i++) {
            int windidx = 0; int idx = i;
            unordered_map<char , int> mpp;

            while(windidx < windsize && idx < s2.size()){
                mpp[s2[idx]]++;
                windidx++;
                idx++;
            }

            if(mp == mpp){
                return true;
            }
        }

        return false;
    }
};
