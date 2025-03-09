class Solution {
public:
    int countSubstrings(string s) {
        unordered_set<string> st;
        int n = s.size();
        int count=0;
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) { 
                l--;
                r++;
                count++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};
