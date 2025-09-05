class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<60;i++){
            long long rem = (long long)num1 - 1LL * i * num2; 
            if (rem < 0) continue;

            int n = __builtin_popcountll(rem);
            if(n <= i && i <= rem) {
                return i;              
            }
        }
        return -1;
    }
};