class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int seq=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cur=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[j-1]){
                    cur++;
                }
                else{
                    break;
                }
            }
            seq=max(cur,seq);
        }
        for(int i=0;i<n;i++){
            int cur=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    cur++;
                }
                else{
                    break;
                }
            }
            seq=max(cur,seq);
        }
        return seq;
    }
};