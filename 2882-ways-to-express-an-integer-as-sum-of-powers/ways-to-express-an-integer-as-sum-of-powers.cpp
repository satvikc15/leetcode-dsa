class Solution {
public:
    const int MOD = 1e9 + 7;

    int fun(int i, int n, int x, vector<vector<int>>& dp) {
        if (n == 0) return 1; 
        if (i == 0) return 0; 
        if (dp[i][n] != -1) return dp[i][n];

        long long p = 1;
        for (int k = 0; k < x; k++) p *= i;

        int take = 0;
        if (p <= n) {
            take = fun(i - 1, n - p, x, dp);
        }
        int skip = fun(i - 1, n, x, dp);

        return dp[i][n] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fun(n, n, x, dp);
    }
};
