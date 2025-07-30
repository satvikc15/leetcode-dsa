class Solution {
public:
    int fun(int i,int j,string text1,string text2,vector<vector<int>>&dp){
        if(i==text1.size() || j==text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0;
        if(text1[i]==text2[j]){
            a = 1 + fun(i+1,j+1,text1,text2,dp);
        }
        b = max(fun(i+1,j,text1,text2,dp),fun(i,j+1,text1,text2,dp));
        return dp[i][j]=max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        for(int i=0;i<=text2.size();i++) dp[text1.size()][i]=0;
        for(int i=0;i<=text1.size();i++) dp[i][text2.size()]=0;

        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                int a=0,b=0;
                if(text1[i]==text2[j]){
                    a = 1 + dp[i+1][j+1];
                }
                b=max(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(a,b);
            }
        }

        return dp[0][0];
    }
};