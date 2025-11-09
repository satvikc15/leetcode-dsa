class Solution {
public:
    int n;
    int fun(int r1,int c1,int r2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int c2=r1+c1-r2;
        if(r1<0 || r1>=n || c1<0 || c1>=n || r2<0 || r2>=n || c2<0 || c2>=n){
            return -1e9;
        }
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9;
        if (r1 == n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1)
            return grid[n-1][n-1];

       
        if(dp[r1][c1][r2]!=INT_MIN) return dp[r1][c1][r2];
        int cherry=0;
        if(r1==r2 && c1==c2){
            cherry=grid[r1][c1];
        }else{
            cherry = grid[r1][c1]+grid[r2][c2];
        }
        int best = max({
            fun(r1+1, c1,   r2+1, grid, dp),
            fun(r1,   c1+1, r2,   grid, dp),  
            fun(r1+1, c1,   r2,   grid, dp),  
            fun(r1,   c1+1, r2+1, grid, dp)   
        });
        cherry+=best;
        return dp[r1][c1][r2]=cherry;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(n,
        vector<int>(n,INT_MIN))) ;
        return max(0, fun(0,0,0,grid,dp));

    }
};