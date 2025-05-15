class Solution {
public:
    int fun(int i,int n,vector<string>& words,map<string,int> &mpp,vector<string>&ans,vector<string>&temp,vector<vector<int>>&dp){
        if(i==n){
            if(ans.size()<temp.size()){
                ans=(temp);
                
            }
            return temp.size();
        }
        if(temp.size()!= 0 && dp[i][mpp[temp.back()]]!=-1) return dp[i][mpp[temp.back()]];
        int take=INT_MIN,notTake=INT_MIN;
        if(temp.size()==0 || mpp[words[i]]!=mpp[temp.back()]){
            temp.push_back(words[i]);
            take = fun(i+1,n,words,mpp,ans,temp,dp);
            temp.pop_back();
            notTake = fun(i+1,n,words,mpp,ans,temp,dp);
        }
        else{
            notTake = fun(i+1,n,words,mpp,ans,temp,dp);
        }
        return temp.size()==0?dp[i][2]=max(take,notTake) : dp[i][mpp[temp.back()]]=max(take,notTake);
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<vector<int>> dp(words.size(),vector<int>(3,-1));
        vector<string> ans;
        vector<string> temp;
        map<string,int> mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]=groups[i];
        }
        int n=words.size();
        fun(0,n,words,mpp,ans,temp,dp);
        return ans;
    }
};