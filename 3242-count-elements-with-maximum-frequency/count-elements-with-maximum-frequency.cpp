class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxFreq=0;
        for(auto it:nums){
            mpp[it]++;
            maxFreq = max(maxFreq,mpp[it]);
        }
        int ans=0;
        for(auto [a,b]:mpp){
            if(b==maxFreq){
                ans+=maxFreq;
            }
        }
        return ans;
    }
};