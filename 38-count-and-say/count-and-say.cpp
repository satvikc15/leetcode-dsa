class Solution {
public:
    string fun(string ans, int i, int n) {
        if (i > n) {
            return ans;
        }
        string temp = "";
        int t = 0;
        for (int j = 1; j < ans.size(); j++) {
            if (ans[j] != ans[t]) {
                int len = j - t;
                temp += to_string(len);
                temp += ans[t];
                t = j;
            }
        }
        int len = ans.size() - t;
        temp += to_string(len);
        temp += ans[t];

        return fun(temp, i + 1, n);
    }

    string countAndSay(int n) {
        return fun("1", 2, n);
    }
};
