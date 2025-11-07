class Solution {
public:
    int fun(int i,vector<vector<int>>&jobs,vector<int>&dp){
        if(i==jobs.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int res = fun(i+1,jobs,dp);
        int l=i+1,r=jobs.size()-1;
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(jobs[mid][0]>=jobs[i][1]){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if (ans != -1)
            res = max(res, jobs[i][2] + fun(ans, jobs, dp));
        else
            res = max(res, jobs[i][2]);
        return dp[i]=res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(jobs.size(),-1);
        return fun(0,jobs,dp);
    }
};