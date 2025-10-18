class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_map<long long, bool> mpp;
        sort(nums.begin(), nums.end());
        long long lastUsed = LLONG_MIN;
        int count = 0;

        for (auto it : nums) {
            long long candidate = max(lastUsed + 1, (long long)it - k);

            if (candidate <= (long long)it + k) {
                mpp[candidate] = true;   
                lastUsed = candidate;  
                count++;
            }
        }
        return count;
    }
};
