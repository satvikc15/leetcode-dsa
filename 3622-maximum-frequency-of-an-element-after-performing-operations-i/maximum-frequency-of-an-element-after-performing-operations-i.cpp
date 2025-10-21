class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mini=1e9;
        int maxi=-1e9;
        for(auto it:nums){
            mini=min(it,mini);
            maxi=max(it,maxi);
        }
        vector<int> freq(maxi+1,0);
        for(auto it:nums){
            freq[it]++;
        }
        for(int i=1;i<=maxi;i++){
            freq[i]+=freq[i-1];
        }
        int ans=0;
        for(int curr=mini;curr<=maxi;curr++){
            int l = max(mini,curr-k);
            int r = min(maxi,curr+k);

            int f = freq[curr]-freq[curr-1];

            int extra = min(numOperations,freq[r]-freq[l-1]-f);

            ans =max(ans,f+extra);
        }
        return ans;
    }
};