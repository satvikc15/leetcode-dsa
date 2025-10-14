class Solution {
public:
    bool pos(int start,int end,vector<int>&nums){
        for(int i=start;i<end-1;i++){
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i+2*k<=n;i++){
            if(pos(i,i+k,nums) && pos(i+k,i+2*k,nums)){
                return true;
            }
        }
        return false;
        
    }
};