class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=i;
            }
            else{
                if(abs(mpp[nums[i]]-i)<=k){
                    return true;
                }
                mpp[nums[i]]=i;
            }
        }
        return false;
    }
};