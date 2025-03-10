class Solution {
    unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
public:
    long long countOfSubstrings(string s, int k) {
        long long a = get(s, k);
        long long b = get(s, k + 1);
        return a - b;
    }
    
    long long get(string s, int k) {
        int i = 0, j = 0, c = 0;
        long long ans = 0;
        unordered_map<char, int> map;
        
        while (i < s.length()) {
            char chi = s[i];
            if (set.count(chi)) {
                map[chi]++;
            } else {
                c++;
            }
            
            while (map.size() == 5 && c >= k) {
                ans += (long long)(s.length() - i);
                char chj = s[j];
                if (set.count(chj)) {
                    if (map[chj] == 1) map.erase(chj);
                    else map[chj]--;
                } else {
                    c--;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};