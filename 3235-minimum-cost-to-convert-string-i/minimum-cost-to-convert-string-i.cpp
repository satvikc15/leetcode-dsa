class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        vector<vector<long long>> mat(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++) {
            mat[i][i] = 0;
        }

        for (int i = 0; i < cost.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            mat[u][v] = min(mat[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (mat[i][k] < INF && mat[k][j] < INF) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            long long d = mat[source[i] - 'a'][target[i] - 'a'];
            if (d == INF) return -1;
            ans += d;
        }

        return ans;
    }
};
