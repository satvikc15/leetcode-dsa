class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum=-1;
        for(auto it:nums){
            if(mpp.find(it)==mpp.end() && it>=0){
                mpp[it]++;
                sum+=it;
            }
        }
        if(sum==-1) return *max_element(nums.begin(),nums.end());
        return sum+1;
    }
};