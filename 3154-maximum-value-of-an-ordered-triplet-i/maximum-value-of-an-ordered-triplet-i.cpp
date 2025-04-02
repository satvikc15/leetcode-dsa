class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    long long temp = (long long)(nums[i] - nums[j]) * nums[k];
                    ans = max(ans, temp);
                }
            }
        }
        return max(ans, 0LL);
    }
};
