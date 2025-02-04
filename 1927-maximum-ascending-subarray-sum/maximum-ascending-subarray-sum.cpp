class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=nums[0];
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curr+=nums[i];
            }
            else{
                maxi=max(curr,maxi);
                curr=nums[i];
            }
        }
        return max(maxi,curr);
    }
};