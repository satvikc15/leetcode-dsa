class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        deque<vector<int>> q;
        map<int,pair<int,int>> dir;
        dir[1]={0,1};
        dir[2]={0,-1};
        dir[3]={1,0};
        dir[4]={-1,0};
        q.push_back({0,0,0});
        int m=grid.size(),n=grid[0].size();
        map<pair<int,int>,int> mpp ;
        mpp[{0,0}]=0;
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int cost = q.front()[2];
            q.pop_front();
            if(r==m-1 && c==n-1){
                return cost;
            }
            for(auto it:dir){
                int dr = it.second.first;
                int dc = it.second.second;
                int nr = r+dr;
                int nc = c+dc;
                int n_cost;
                if(it.first==grid[r][c]){
                    n_cost=cost;
                }
                else{
                    n_cost=cost+1;
                }
                if(nr<0 || nc<0 || nr==m || nc == n || mpp.find({nr,nc})!=mpp.end() && mpp[{nr,nc}]<=n_cost){
                    continue;
                }
                mpp[{nr,nc}]=n_cost;
                if(it.first==grid[r][c]){
                    q.push_front({nr,nc,n_cost});
                }
                else{
                    q.push_back({nr,nc,n_cost});
                }
            }
        }
        return -1;
    }
};