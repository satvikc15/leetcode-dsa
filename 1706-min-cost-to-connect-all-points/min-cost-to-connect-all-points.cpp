class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);  

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        unordered_set<int> v; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});
        int cost = 0;
        vector<bool> visited(n, false);

        while (v.size() < n) { 
            auto [c, i] = pq.top();
            pq.pop();
            if (visited[i]) continue; 
            visited[i] = true;
            cost += c;
            v.insert(i);
            for (auto& it : adj[i]) {
                if (!visited[it.second]) {
                    pq.push({it.first, it.second}); 
                }
            }
        }
        return cost;
    }
};
