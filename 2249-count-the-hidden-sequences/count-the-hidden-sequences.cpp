class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minSum = 0, maxSum = 0, current = 0;
        for (int diff : differences) {
            current += diff;
            minSum = min(minSum, current);
            maxSum = max(maxSum, current);
        }
        long startMin = lower - minSum;
        long startMax = upper - maxSum;
        return max(0L, startMax - startMin + 1);
    }
};
