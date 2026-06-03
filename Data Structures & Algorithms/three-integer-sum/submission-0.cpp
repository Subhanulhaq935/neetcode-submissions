class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> store;
        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                if (st.find(third) != st.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    store.insert(temp);
                }
                st.insert(nums[j]);
            }
        }

        ans = vector<vector<int>>(store.begin() , store.end());
        return ans;
    }
};
