class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int& time, int& fresh) {
        queue<pair<int, int>> q;
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            int sz = q.size();
            bool rotted = false;
            for (int i = 0; i < sz; i++) {
                auto [a, b] = q.front();
                q.pop();
                for (auto [k, l] : dir) {
                    int ni = a + k;
                    int nj = b + l;
                    if (ni >= 0 && nj >= 0 && ni < rows && nj < cols &&
                        grid[ni][nj] == 1 && !vis[ni][nj]) {
                        q.push({ni, nj});
                        vis[ni][nj] = true;
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if (rotted) time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, time = 0;
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) fresh++;
            }
        }

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        bfs(grid, vis, time, fresh);

        return fresh == 0 ? time : -1;
    }
};
