class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(auto it:nums){
            sum+=it;
            ans+=mpp[sum-k];
            mpp[sum]++;

        }
        return ans;
    }
};