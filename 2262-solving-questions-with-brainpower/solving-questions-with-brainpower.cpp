class Solution {
public:
    long long fun(int i,vector<vector<int>>& questions,vector<long long>&dp){
        if(i>=questions.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        long long pick=questions[i][0]+fun(i+questions[i][1]+1,questions,dp);
        long long notPick=fun(i+1,questions,dp);
        return dp[i]=max(pick,notPick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return fun(0,questions,dp);
    }
};