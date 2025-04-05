class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long max_val = 0;
        int max_i = nums[0];
        int best_diff = INT_MIN;

        for (int j = 1; j < n - 1; ++j) {
            best_diff = max(best_diff, max_i - nums[j]);
            max_val = max(max_val, 1LL * best_diff * nums[j + 1]);
            max_i = max(max_i, nums[j]);
        }

        return max_val;
    }
};
