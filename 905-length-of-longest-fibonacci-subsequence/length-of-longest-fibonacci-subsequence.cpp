class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0;
        unordered_set<int> s(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j];
                int count = 2;
                while (s.find(a + b) != s.end()) {
                    int c = a + b;
                    a = b;
                    b = c;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res > 2 ? res : 0;
    }
};
