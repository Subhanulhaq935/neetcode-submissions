class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int n = prices.size();
        int mini = prices[0];

        for(int i = 1 ; i < n ; i++)
        {
            maxi = max(maxi , prices[i] - mini);
            mini = min(mini ,prices[i]);
        }

        return maxi;
    }
};
