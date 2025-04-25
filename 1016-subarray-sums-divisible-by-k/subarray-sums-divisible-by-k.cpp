class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int ans = 0, sum = 0;

        for(int num : nums) {
            sum = (sum + num + k) % k;
            if (sum < 0) sum += k; 
            ans += mpp[sum];
            mpp[sum]++;
        }

        return ans;
    }
};
