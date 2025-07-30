class Solution {
public:
    int fun(int i,int j,string word1,string word2,vector<vector<int>>&dp){
        if (j == word2.size()) {
            return word1.size() - i;
        }
        if(i==word1.size()){
            return word2.size() - j;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=fun(i+1,j+1,word1,word2,dp);
        }
        int a = 1 + fun(i,j+1,word1,word2,dp);
        int b = 1 + fun(i+1,j,word1,word2,dp);
        int c = 1 + fun(i+1,j+1,word1,word2,dp);
        return dp[i][j] = min(a,min(b,c));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return fun(0,0,word1,word2,dp);

    }
};