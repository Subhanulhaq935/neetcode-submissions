class Solution {
   public:
    int n;
    vector<int> dp;
    int solve(vector<int>& stoneValue, int i) {
        if (i >= n) return 0;

        if(dp[i] != INT_MIN) return dp[i];

        int result = stoneValue[i] - solve(stoneValue, i + 1);

        if (i + 1 < n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] - solve(stoneValue, i + 2));
        }
        if (i + 2 < n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                                     solve(stoneValue, i + 3));
        }

        return dp[i] =  result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n + 1 , INT_MIN);

        int diff = solve(stoneValue, 0);
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        if (diff == 0) return "Tie";
    }
};