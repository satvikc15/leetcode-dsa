class Solution {
public:
    bool canFind(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) inc[i] = inc[i - 1] + 1;
        }

        for (int a = 0; a + 2 * k <= n; a++) {
            int mid = a + k;
            if ( inc[a + k - 1] >= k && inc[a + 2 * k - 1] >= k)
                return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n / 2, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFind(nums, mid)) {
                ans = mid;         
                low = mid + 1;    
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
