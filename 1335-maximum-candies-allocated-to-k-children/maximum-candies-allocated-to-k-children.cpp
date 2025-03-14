class Solution {
public:
    bool pos(vector<int>& candies, int mid, long long k) {
        long long count = 0;
        for (int it : candies) {
            count += it / mid;
            if (count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (pos(candies, mid, k)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
