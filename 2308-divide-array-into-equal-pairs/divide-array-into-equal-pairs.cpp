class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        //if(mpp.size()>nums.size()/2) return false;
        for(auto it:mpp){
            if(it.second%2!=0) return false;
        }
        return true;
    }
};