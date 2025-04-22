class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]!=1) q.push({1,{0,0}});
        else return -1;
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        dist[0][0]=0;
        while(!q.empty()){
            int cost=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(i==n-1 && j==n-1) return cost;
            for(auto [a,b]:dir){
                int ni=i+a;
                int nj=j+b;
                if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==0){
                    if(cost+1<dist[ni][nj]){
                        dist[ni][nj]=cost+1;
                        q.push({cost+1,{ni,nj}});
                    }
                }
            }
        }
        return -1;
    }
};