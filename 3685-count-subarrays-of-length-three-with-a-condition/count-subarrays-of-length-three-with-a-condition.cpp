class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int slow=0,fast=2;
        int count=0;
        while(fast<nums.size()){
            if((nums[slow]+nums[fast])*2==nums[slow+1]) count++;

            fast++;
            slow++;
        }
        return count;
    }
};