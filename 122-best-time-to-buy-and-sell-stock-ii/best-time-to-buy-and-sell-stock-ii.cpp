class Solution {
public:
    int fun(int i, int holding, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][holding] != -1) return dp[i][holding];

        int skip = fun(i + 1, holding, prices, dp);
        int buySell = 0;

        if (holding == 0) {
            buySell = -prices[i] + fun(i + 1, 1, prices, dp);
        } else {
            buySell = prices[i] + fun(i + 1, 0, prices, dp);
        }

        return dp[i][holding] = max(skip, buySell);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fun(0, 0, prices, dp); 
    }
};
