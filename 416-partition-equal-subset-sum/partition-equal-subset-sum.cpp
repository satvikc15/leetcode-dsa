class Solution {
public:
    bool f(int index,vector<int>& nums,int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(index==0) return target-nums[index]==0;
        if(dp[index][target]!=-1) return dp[index][target];
        bool notPick = f(index-1,nums,target,dp);
        bool pick = false;
        if(target>=nums[index]) pick = f(index-1,nums,target-nums[index],dp);
        return dp[index][target]=notPick||pick;
    }
    bool canPartition(vector<int>& nums) {
        long long n = accumulate(nums.begin(), nums.end(), 0);
        if(n%2!=0) return false;
        vector<vector<int>>dp(nums.size(),vector<int>(n/2+1,-1));
        return f(nums.size()-1,nums,n/2,dp);
    }
};