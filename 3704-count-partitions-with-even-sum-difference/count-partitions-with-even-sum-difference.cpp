class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int count=0;
        int satvik = 0;
        for(int i=0;i<nums.size()-1;i++){
            sum-=nums[i];
            satvik+=nums[i];
            if(abs(sum-satvik)%2==0){
                count++;
            }
        }
        return count;
    }
};