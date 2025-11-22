class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans+=min(it%3,abs(3-it%3));
        }
        return ans;
    }
};