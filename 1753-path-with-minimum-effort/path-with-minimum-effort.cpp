class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!pq.empty()) {
            auto [diff, pos] = pq.top();
            pq.pop();
            int i = pos.first, j = pos.second;
            if (i == n - 1 && j == m - 1) return diff;

            for (auto [a, b] : dir) {
                int ni = i + a, nj = j + b;
                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    int newEffort = max(diff, abs(heights[i][j] - heights[ni][nj]));
                    if (newEffort < dist[ni][nj]) {
                        dist[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
