class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int l=0,n=1,r=2;
        if(nums.size()<3) return 0;
        
        while(n<nums.size()-1){
            while(l>=0 && nums[l]==nums[n]){
                l--;
            }
            while(r<nums.size() && nums[r]==nums[n]){
                r++;
            }
            if(l>=0 && r<nums.size() && ((nums[l]>nums[n] && nums[r]>nums[n])||(nums[l]<nums[n] && nums[r]<nums[n]))){
                count++;
            }
            n=r;
            r=n+1;
            l=n-1;
            
        }
        return count;
    }
};