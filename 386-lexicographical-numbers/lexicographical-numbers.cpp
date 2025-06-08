class Solution {
public:
    void fun(int i, vector<int>& ans, int n) {
        if(i > n) return;
        ans.push_back(i);
        for(int j = 0; j < 10; ++j) {
            if(i * 10 + j > n) break;
            fun(i * 10 + j, ans, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= 9; ++i) {
            fun(i, ans, n);
        }
        return ans;
    }
};
