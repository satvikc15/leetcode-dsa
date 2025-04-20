class Solution {
public:
    int m, n;
    bool invalid;

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            invalid = true;

        int count = 1;
        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        for (auto [dx, dy] : dir) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj] && grid[ni][nj] == 1) {
                count += dfs(ni, nj, grid, visited);
            }
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    invalid = false;
                    int cells = dfs(i, j, grid, visited);
                    if (!invalid)
                        total += cells;
                }
            }
        }
        return total;
    }
};
