class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto it:nums){
            if(mpp.find(it)!=mpp.end()){
                ans.push_back(it);
            }else{
                mpp[it]++;
            }
        }
        return ans;
    }
};