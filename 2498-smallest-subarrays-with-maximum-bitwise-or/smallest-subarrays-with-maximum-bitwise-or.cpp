class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> last(32, -1); 
        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) last[b] = i;
            }
            int maxIdx = i;
            for (int b = 0; b < 32; ++b) {
                if (last[b] != -1) maxIdx = max(maxIdx, last[b]);
            }
            ans[i] = maxIdx - i + 1;
        }
        return ans;
    }
};
