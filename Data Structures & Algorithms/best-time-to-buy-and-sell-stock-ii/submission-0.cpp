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
                maxi = maxi + prices[j] - prices[i];
                i++;
                j++;
            }
        }

        return maxi;
    }
};
