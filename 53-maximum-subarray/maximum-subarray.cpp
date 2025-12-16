class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int r=0;
        int fin=0;
        while(r<nums.size()){
            ans+=nums[r];
            fin=max(ans,fin);
            if(ans<0){
                ans=0;
            }
            
            r++;
        }
        if(fin==0) return *max_element(nums.begin(),nums.end());
        return fin;
    }
};