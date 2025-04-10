class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0;

        mpp[0] = -1; 
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (k != 0) {
                sum %= k; 
            }
            
            if (mpp.find(sum) != mpp.end()) {
                if (i - mpp[sum] >= 2) { 
                    return true;
                }
            } else {
                mpp[sum] = i; 
            }
        }
        return false;
    }
};
