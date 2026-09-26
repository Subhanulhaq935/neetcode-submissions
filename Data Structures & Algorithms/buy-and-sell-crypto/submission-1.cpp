class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int i = 0;
        int j = 1;

        while(j < n)
        {
            if(prices[i] > prices[j])
            {
                i = j;
                j++;
            }
            else{
                maxi = max(maxi , prices[j] - prices[i]);
                j++;
            }
        }

        return maxi;
    }
};
