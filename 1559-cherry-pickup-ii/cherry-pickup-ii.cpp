class Solution {
public:
    int n, m;
    int fun(int row, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return -1e9; 

        if (row == n - 1) { 
            if (c1 == c2) return grid[row][c1];
            else return grid[row][c1] + grid[row][c2];
        }

        if (dp[row][c1][c2] != INT_MIN)
            return dp[row][c1][c2];

        int cherries = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];

        int best = -1e9;
        for (int dc1 = -1; dc1 <= 1; dc1++) {
            for (int dc2 = -1; dc2 <= 1; dc2++) {
                best = max(best, fun(row + 1, c1 + dc1, c2 + dc2, grid, dp));
            }
        }

        return dp[row][c1][c2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
        return fun(0, 0, m - 1, grid, dp);
    }
};
