class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int j = 0;
        int sum = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++;
            } else if (j < 31 && sum + (1 << j) <= k) {
                count++;
                sum += (1 << j);
            }
            j++;
        }
        return count;
    }
};
