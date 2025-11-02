class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> graph(m, vector<bool>(n, false));
        vector<vector<bool>> isGuard(m, vector<bool>(n, false));
        set<pair<int,int>> w;
        for (auto& v : walls) w.insert({v[0], v[1]});

        for (auto& g : guards) {
            isGuard[g[0]][g[1]] = true;
            graph[g[0]][g[1]] = true;
        }

        for (auto& g : guards) {
            int x = g[0], y = g[1];

            for (int j = y - 1; j >= 0; j--) {
                if (w.count({x, j}) || isGuard[x][j]) break;
                graph[x][j] = true;
            }

            for (int j = y + 1; j < n; j++) {
                if (w.count({x, j}) || isGuard[x][j]) break;
                graph[x][j] = true;
            }

            for (int i = x - 1; i >= 0; i--) {
                if (w.count({i, y}) || isGuard[i][y]) break;
                graph[i][y] = true;
            }

            for (int i = x + 1; i < m; i++) {
                if (w.count({i, y}) || isGuard[i][y]) break;
                graph[i][y] = true;
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!graph[i][j] && !w.count({i, j})) count++;
            }
        }
        return count;
    }
};
