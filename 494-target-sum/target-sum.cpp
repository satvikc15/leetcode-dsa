class Solution {
public:
    int fun(int i,vector<int>& nums,int a,int b, int target,vector<vector<int>>&dp){
        if(i==nums.size()){
            if((b-a)-a==target) return 1;
            return 0;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        int count=fun(i+1,nums,a+nums[i],b,target,dp);
        count+=fun(i+1,nums,a,b,target,dp);
        return dp[i][a]=count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(totsum+1,-1));
        return fun(0,nums,0,totsum,target,dp);
    }
};