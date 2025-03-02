class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mpp;
        for(auto it: nums1){
            mpp[it[0]]=it[1];
        }
        for(auto it:nums2){
            if(mpp.find(it[0])!=mpp.end()){
                mpp[it[0]]+=it[1];
            }
            else mpp[it[0]]=it[1];
        }
        vector<vector<int>> ans;
        for(auto it:mpp){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};