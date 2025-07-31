class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(it.second+cost<dist[it.first]){
                    dist[it.first]=it.second+cost;
                    pq.push({it.second+cost,it.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(dist[i],ans);
        }
        return ans==1e9?-1:ans;
    }
};