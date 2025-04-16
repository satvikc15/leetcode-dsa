class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long pairs = 0, ans = 0;
        map<int, int> mpp;
        while (r < nums.size()) {
            mpp[nums[r]]++;
            if (mpp[nums[r]] > 1) pairs += mpp[nums[r]] - 1;
            while (pairs >= k) {
                ans += nums.size() - r;
                mpp[nums[l]]--;
                if (mpp[nums[l]] >= 1) pairs -= mpp[nums[l]];
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
