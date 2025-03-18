class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr=0;
        int l=0,r=0;
        int res=0;
        while(r<nums.size()){
            if((curr&nums[r])==0){
                curr|=nums[r];
                r++;
            }
            else{
                curr^=nums[l];
                l++;
            }
            res=max(res,r-l);
        }
        return res;
    }
};