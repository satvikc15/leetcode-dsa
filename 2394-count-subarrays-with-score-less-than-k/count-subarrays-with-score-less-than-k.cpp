class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0,r=0;
        long long sum=0LL;
        long long ans=0LL;
        while(r<nums.size()){
            sum+=nums[r];
            while((r-l+1)*sum>=k && l<=r){
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};