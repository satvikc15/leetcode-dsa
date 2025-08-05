class Solution {
public:
    int fun(int i,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];

        int a=0,b=0;
        if(buy){
            a=max(-prices[i]+fun(i+1,!buy,prices,dp,fee),fun(i+1,buy,prices,dp,fee));
        }
        else{
           b=max(+prices[i]-fee+fun(i+1,!buy,prices,dp,fee),fun(i+1,buy,prices,dp,fee)); 
        }
        return dp[i][buy]=max(a,b);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fun(0,1,prices,dp,fee);
    }
};