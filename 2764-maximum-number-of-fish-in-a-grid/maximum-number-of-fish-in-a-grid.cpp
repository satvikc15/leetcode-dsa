class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        int res = grid[i][j];
        vector<vector<int>> directions = {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
        
        for (auto& dir : directions) {
            int a = dir[0];
            int b = dir[1];
            if (a >= 0 && b >= 0 && a < grid.size() && b < grid[0].size() && !visited[a][b] && grid[a][b] > 0) {
                res += dfs(a, b, grid, visited);
            }
        }
        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0 && visited[i][j] == 0) {
                    res = max(dfs(i, j, grid, visited), res);
                }
            }
        }
        return res;
    }
};
