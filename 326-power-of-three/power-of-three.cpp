class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        long long p = 1;
        while (p < n) {
            p *= 3;
        }
        return p == n;
    }
};
