class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int n : nums)
        {
            st.insert(n);
        }

        int lon = 0;

        for(auto it : st)
        {
            if(st.find(it - 1) == st.end())
            {
                int current = it;
                int lenght = 1;

                while(st.find(current + 1) != st.end())
                {
                    current++;
                    lenght++;
                }

                lon = max(lon , lenght);

            }
        }

        return lon;
    }
};
