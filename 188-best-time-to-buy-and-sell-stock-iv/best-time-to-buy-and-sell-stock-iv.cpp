class Solution {
public:
    int fun(int i,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(cap==0){
            return 0;
        }
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int a=0;
        int b=0;
        if(buy==1){
            a=max(-prices[i]+fun(i+1,0,cap,prices,dp),fun(i+1,1,cap,prices,dp));
        }
        else{
            b=max(+prices[i]+fun(i+1,1,cap-1,prices,dp),fun(i+1,0,cap,prices,dp));
        }
        return dp[i][buy][cap]=max(a,b);
    } 
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,1,k,prices,dp);
    }
};