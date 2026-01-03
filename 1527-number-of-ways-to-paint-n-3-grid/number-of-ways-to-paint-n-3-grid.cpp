class Solution {
public:
    int mod = 1e9+7;
    int solve(int r,int prev1,int prev2,int prev3,int n,vector<vector<vector<vector<int>>>>&dp){
        if(r==n){
            return 1;
        }
        if(dp[r][prev1+1][prev2+1][prev3+1]!=-1){
            return dp[r][prev1+1][prev2+1][prev3+1];
        }
        int ans=0;
        for(int c1=0;c1<3;c1++){
            for(int c2=0;c2<3;c2++){
                for(int c3=0;c3<3;c3++){
                    if(c1!=c2 && c2!=c3 && prev1!=c1 && prev2!=c2 && prev3!=c3){
                        ans = (ans+solve(r+1,c1,c2,c3,n,dp))%mod;
                    }
                }
            }
        }
        return dp[r][prev1+1][prev2+1][prev3+1]=ans;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n, 
            vector<vector<vector<int>>>(4, 
                vector<vector<int>>(4, 
                    vector<int>(4, -1))));
        return solve(0,-1,-1,-1,n,dp);
    }
};