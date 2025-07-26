class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMaxi=0,currMini=0;
        int maxi=nums[0],mini=nums[0];
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
            currMaxi = max(currMaxi+it,it);
            maxi = max(maxi,currMaxi);

            currMini = min(currMini+it,it);
            mini = min(mini,currMini);
        }
        if(maxi<0) return maxi;
        return max(maxi,totsum-mini);
    }
};