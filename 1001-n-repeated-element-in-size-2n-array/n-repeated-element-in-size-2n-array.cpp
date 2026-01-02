class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size()/2;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it]==n) return it;
        }
        return -1;
    }
};