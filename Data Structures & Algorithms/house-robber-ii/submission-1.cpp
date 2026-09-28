class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        // Skip last
        vector<int> arr1;

        for (int i = 0; i < n - 1; i++) {
            arr1.push_back(nums[i]);
        }

        // Skip first
        vector<int> arr2;

        for (int i = 1; i < n; i++) {
            arr2.push_back(nums[i]);
        }

        // Case 1
        vector<int> dp1(arr1.size(), 0);

        dp1[0] = arr1[0];
        dp1[1] = max(arr1[0], arr1[1]);

        for (int i = 2; i < arr1.size(); i++) {
            dp1[i] = max(dp1[i - 2] + arr1[i],
                         dp1[i - 1]);
        }

        // Case 2
        vector<int> dp2(arr2.size(), 0);

        dp2[0] = arr2[0];
        dp2[1] = max(arr2[0], arr2[1]);

        for (int i = 2; i < arr2.size(); i++) {
            dp2[i] = max(dp2[i - 2] + arr2[i],
                         dp2[i - 1]);
        }

        return max(dp1[arr1.size() - 1],
                   dp2[arr2.size() - 1]);
    }
};