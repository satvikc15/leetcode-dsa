class Solution {
public:
    int fun(string &s, string pair, int score) {
        int count = 0;
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(!st.empty() && st.top() == pair[0] && pair[1] == s[i]) {
                st.pop();
                count += score;
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return count;
    }

    int maximumGain(string s, int x, int y) {
        string pair1 = x > y ? "ab" : "ba";
        string pair2 = x > y ? "ba" : "ab";
        int count = fun(s, pair1, max(x, y));
        count += fun(s, pair2, min(x, y));
        return count;
    }
};
