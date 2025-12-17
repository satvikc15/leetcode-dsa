class Solution {
public:
    void fun(int i,vector<int>& candidates, int target,vector<int>& temp,set<vector<int>>&ans){
        if(target==0){
            ans.insert(temp);
        }
        if(i==candidates.size()) return;
        if(target-candidates[i]>=0) {
            temp.push_back(candidates[i]);
            fun(i,candidates,target-candidates[i],temp,ans);
            temp.pop_back();            
        }
        fun(i+1,candidates,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        fun(0,candidates,target,temp,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};