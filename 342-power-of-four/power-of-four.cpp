class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        long long p = 1;
        while (p < n) {
            p *= 4;
        }
        return p == n;
    }
};