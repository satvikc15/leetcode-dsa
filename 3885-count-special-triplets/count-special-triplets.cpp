class Solution {
public:
    int mod = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<long long,int> mpp1, mpp2;

        long long ans = 0;

        for (auto it : nums) mpp1[it]++;

        mpp1[nums[0]]--;
        if (mpp1[nums[0]] == 0) mpp1.erase(nums[0]);
        mpp2[nums[0]]++;

        for (int i = 1; i < nums.size() - 1; i++) {

            mpp1[nums[i]]--;
            if (mpp1[nums[i]] == 0) mpp1.erase(nums[i]);

            long long x = 1LL * nums[i] * 2;  

            if (mpp1.count(x) && mpp2.count(x)) {
                ans = (ans + (1LL * mpp1[x] % mod) * (mpp2[x] % mod)) % mod;
            }

            mpp2[nums[i]]++;
        }

        return ans;
    }
};
