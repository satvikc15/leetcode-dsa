class Solution {
public:
    int fun(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];

        int a=0,b=0;
        if(buy){
            a=max(-prices[i]+fun(i+1,!buy,prices,dp),fun(i+1,buy,prices,dp));
        }
        else{
           b=max(+prices[i]+fun(i+2,!buy,prices,dp),fun(i+1,buy,prices,dp)); 
        }
        return dp[i][buy]=max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fun(0,1,prices,dp);
    }
};