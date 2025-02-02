class Solution {
public:
    bool check(vector<int>& arr) {
        int count = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[(i + 1) % n]) count++;
            if (count > 1) return false;
        }
        return true;
    }
};
