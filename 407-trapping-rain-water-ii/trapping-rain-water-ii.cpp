class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int R=grid.size(),C=grid[0].size();
        vector<vector<int>> vis(R,vector<int>(C,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i==0 || i==R-1 || j==0 || j==C-1){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int vol=0;
        int minBht=0;
        while(!pq.empty()){
            int curr = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            minBht=max(curr,minBht);
            pq.pop();
            int dr[4] = {0,0,1,-1};
            int dc[4] = {1,-1,0,0};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0|| nr==R || nc==C || vis[nr][nc]==1){
                    continue;
                }
                else{
                    pq.push({grid[nr][nc],{nr,nc}});
                    vis[nr][nc]=1;
                    if(grid[nr][nc]<minBht){
                        vol+=minBht-grid[nr][nc];
                    }
                }

            }
        }
        return vol;
    }
};