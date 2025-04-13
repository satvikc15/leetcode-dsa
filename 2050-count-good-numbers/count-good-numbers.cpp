#define mod 1000000007
class Solution {
public:
    long long power(long long base, long long exp) {
        long long result = 1;
        while(exp > 0) {
            if(exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        return (power(5, evenCount) * power(4, oddCount)) % mod;
    }
};
