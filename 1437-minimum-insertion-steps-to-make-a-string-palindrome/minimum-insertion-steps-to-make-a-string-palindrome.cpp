class Solution {
public:
    int fun(int i,int j,string &s,vector<vector<int>>&dp){
        if(j<i){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            dp[i][j]=fun(i+1,j-1,s,dp);
        }
        else{
            dp[i][j]=1+min(fun(i+1,j,s,dp),fun(i,j-1,s,dp));
        }
        return dp[i][j];
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return fun(0,s.size()-1,s,dp);
    }
};