class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }
        vector<int> ans;
        int temp = 0, last = 0;
        for (int i = 0; i < s.size(); i++) {
            temp = max(temp, mpp[s[i]]);
            if (i == temp) {
                ans.push_back(i - last + 1);
                last = i + 1;
            }
        }
        return ans;
    }
};
