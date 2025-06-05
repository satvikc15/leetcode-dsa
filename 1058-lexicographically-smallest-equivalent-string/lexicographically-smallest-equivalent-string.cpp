class Solution {
public:
    int fup(int c, vector<int> &par) {
        if (par[c] == c) {
            return par[c];
        } else {
            return par[c] = fup(par[c], par);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26, 0);
        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }

        int n = s1.size();
        for (int i = 0; i < n; i++) {
            int u = fup(s1[i] - 'a', par);
            int v = fup(s2[i] - 'a', par);
            if (u > v) {
                par[u] = v;
            } else {
                par[v] = u;
            }
        }

        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = fup(baseStr[i] - 'a', par) + 'a';
        }

        return baseStr;
    }
};
