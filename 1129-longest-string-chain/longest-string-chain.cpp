class Solution {
public:
    bool pos(string a, string b) {
        if (a.size() - b.size() != 1) return false;
        for (int i = 0; i < a.size(); i++) {
            string temp = a.substr(0, i) + a.substr(i + 1);
            if (temp == b) return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        int n=words.size();
        vector<int> dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pos(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};