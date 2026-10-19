class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> store;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> hashset;

                for (int k = j + 1; k < n; k++) {
                    long long fourth = (long long)target
                                     - nums[i] - nums[j] - nums[k];

                    if (fourth >= INT_MIN && fourth <= INT_MAX &&
                        hashset.find((int)fourth) != hashset.end()) {

                        vector<int> temp = {
                            nums[i], nums[j], nums[k], (int)fourth
                        };

                        sort(temp.begin(), temp.end());
                        store.insert(temp);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(store.begin(), store.end());
    }
};