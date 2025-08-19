class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       int l=0,r=0;
       long long ans=0;
       int n=nums.size();
       while(r<n) {
            if(nums[r]!=0){
                r++;
                l++;
            }
            else{
                while(r<n && nums[r]==0){
                    
                    ans+=(r-l+1);
                    r++;
                }
                l=r;
            }
            
       }
       return ans;
    }
};