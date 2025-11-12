class Solution {
public:
    bool fun(int i, int j, string &s, string &p,vector<vector<int>> &dp) {
        if (j == p.size()) return i == s.size();
        if (i == s.size()) {
            for (int k = j; k < p.size(); k++)
                if (p[k] != '*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (p[j] == s[i] || p[j] == '?')
            return dp[i][j]=fun(i + 1, j + 1, s, p,dp);

        if (p[j] == '*')
            return dp[i][j]=(fun(i, j + 1, s, p,dp) || fun(i + 1, j, s, p,dp));

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return fun(0, 0, s, p,dp);
    }
};
