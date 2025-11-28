class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; i++)
            pref[i+1] = pref[i] + nums[i];

        long long ans = LLONG_MIN;

        vector<long long> best(k, LLONG_MAX);

        for (int i = 0; i <= n; i++) {
            int r = i % k;

            if (best[r] != LLONG_MAX) {
                ans = max(ans, pref[i] - best[r]);
            }

            best[r] = min(best[r], pref[i]);
        }

        return ans;
    }
};
