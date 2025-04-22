class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{-1,src}});
        while(!q.empty()){
            int cost=q.front().first;
            int step=q.front().second.first;
            int node=q.front().second.second;
            q.pop();
            //if(node==dst) return cost;
            for(auto it:adj[node]){
                int i=it.first;
                int pr=it.second;
                if(cost+pr<dist[i]&&step+1<=k){
                    dist[i]=cost+pr;
                    q.push({dist[i],{step+1,i}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};