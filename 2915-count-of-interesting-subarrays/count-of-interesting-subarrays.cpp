class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> mpp;
        int prefix_count = 0;
        mpp[0] = 1;
        long long ans = 0;

        for (auto it : nums) {
            if (it % modulo == k) {
                prefix_count = (prefix_count + 1) % modulo;
            }

            ans += mpp[(prefix_count - k + modulo) % modulo];
            mpp[prefix_count]++;
        }

        return ans;
    }
};
