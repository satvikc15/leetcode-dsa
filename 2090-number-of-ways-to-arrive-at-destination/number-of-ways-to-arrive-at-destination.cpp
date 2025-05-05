class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if(d > dist[node]) continue;

            for(auto& [nei, wt] : adj[node]){
                if(d + wt < dist[nei]){
                    dist[nei] = d + wt;
                    ways[nei] = ways[node];
                    pq.push({dist[nei], nei});
                } else if(d + wt == dist[nei]){
                    ways[nei] = (ways[nei] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
