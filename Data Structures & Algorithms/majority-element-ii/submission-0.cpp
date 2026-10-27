
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        for (auto it : mp) {
            if (it.second > nums.size() / 3) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};
