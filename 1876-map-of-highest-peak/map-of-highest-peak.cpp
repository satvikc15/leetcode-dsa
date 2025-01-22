class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>> res(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            int h=res[r][c];
            q.pop();
            vector<pair<int,int>> dir = {{r,c-1},{r+1,c},{r-1,c},{r,c+1}};
            for(auto it:dir){
                int nr=it.first;
                int nc=it.second;
                if(nr<0 || nc <0 || nr==n || nc==m || res[nr][nc]!=-1){
                    continue;
                }
                res[nr][nc]=h+1;
                q.push({nr,nc});
            }

        }
        return res;
    }
};