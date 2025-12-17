class Solution {
public:
    void fun(int i,vector<int>& nums,set<vector<int>> &ans,vector<int> &temp){
        if(i==nums.size()){
            ans.insert(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        fun(i+1,nums,ans,temp);
        temp.pop_back();
        fun(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        fun(0,nums,ans,temp);
        return vector<vector<int>>(ans.begin(),ans.end());

    }
};