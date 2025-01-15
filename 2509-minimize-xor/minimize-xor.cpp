class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        while (num2) {
            if (num2 & 1) {
                count++;
            }
            num2 >>= 1;
        }
        vector<int> bitset1(32, 0), bitset2(32, 0);
        int i = 0;
        while (num1) {
            if (num1 & 1) {
                bitset1[i] = 1;
            }
            i++;
            num1 >>= 1;
        }
        for (i = 31; i >= 0; i--) {
            if (bitset1[i] && count) {
                count--;
                bitset2[i] = 1;
            }
        }
        i = 0;
        while (count > 0) {
            if (bitset2[i] == 0) {
                count--;
                bitset2[i] = 1;
            }
            i++;
        }
        int ans = 0;
        for (i = 0; i < 32; i++) {
            if (bitset2[i]) {
                ans += (1 << i);
            }
        }
        return ans;
    }
};
