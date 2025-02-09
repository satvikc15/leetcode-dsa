class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long nop = (long long)n*(n-1)/2;
        unordered_map<long long,int> mpp;
        long long count=0LL;
        for(int i=0;i<n;i++){
            mpp[nums[i]-i]++;
            
        }
        for(auto it:mpp){
            int k=it.second;
            if(k>1){
                count+=(long long)(k-1)*k/2;
            }
        }
        return nop-count;
    }
};