class Solution {
public:
    int mod = 1000000007; 
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (int i = 31; i >= 0; i--) { 
            long long power = 1LL << i;
            while (n >= power) {
                ans.push_back(power);
                n -= power;
            }
        }

        reverse(ans.begin(), ans.end());

        vector<int> fin;
        for (auto &q : queries) {
            long long temp = 1;
            for (int j = q[0]; j <= q[1]; j++) {
                temp = (temp * ans[j]) % mod;
            }
            fin.push_back((int)temp);
        }
        
        return fin;
    }
};
