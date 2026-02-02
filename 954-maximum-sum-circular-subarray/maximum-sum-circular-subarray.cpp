class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmax=0;
        int gmax=nums[0];
        int curmin=0;
        int gmin=nums[0];
        int total=0;
        for(int i=0;i<nums.size();i++){
            curmax=max(curmax+nums[i],nums[i]);
            gmax=max(curmax,gmax);
            curmin=min(curmin+nums[i],nums[i]);
            gmin=min(curmin,gmin);
            total+=nums[i];
        }
        //cout << gmax<< endl;
        if(gmax<0){
            return gmax;
        }else{
            return max(gmax,total-gmin);
        }
    }
};