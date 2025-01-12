class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(mpp.find(temp)!=mpp.end()){
                return {i,mpp[temp]};
            }
            mpp[nums[i]]=i;
        }
        return {-1};
    }
};