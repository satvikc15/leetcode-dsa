class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans;
        vector<bool> t(nums.size(),false);
        for(int i=temp.size()-k;i<temp.size();i++){
            t[temp[i].second]=true;
        }
        for(int i=0;i<nums.size();i++){
            if(t[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};