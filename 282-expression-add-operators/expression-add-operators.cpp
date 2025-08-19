class Solution {
public:
    void fun(int i, string num, long cursum, long prev, int target, string temp, vector<string>& ans) {
        if (i == num.size()) {
            if (target == cursum) {
                ans.push_back(temp);
            }
            return;
        }

        for (int j = i; j < num.size(); j++) {
            string n = num.substr(i, j - i + 1);

            if (n[0] == '0' && n.size() > 1) break;

            long a = stol(n);

            if (i == 0) {
                fun(j + 1, num, a, a, target, temp + n, ans);
            } else {
                fun(j + 1, num, cursum + a, a, target, temp + "+" + n, ans);
                fun(j + 1, num, cursum - a, -a, target, temp + "-" + n, ans);
                fun(j + 1, num, cursum - prev + prev * a, prev * a, target, temp + "*" + n, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        fun(0, num, 0, 0, target, "", ans);
        return ans;
    }
};
