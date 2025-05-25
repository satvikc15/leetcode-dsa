class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mpp;
        for (auto it : words) {
            mpp[it]++;
        }

        int ans = 0;
        bool centralUsed = false;

        for (auto& [word, count] : mpp) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                ans += (count / 2) * 4;
                if (count % 2) centralUsed = true;
            } else if (mpp.find(rev) != mpp.end()) {
                int pairCount = min(count, mpp[rev]);
                ans += pairCount * 4;
                mpp[rev] = 0;
                mpp[word] = 0;
            }
        }

        if (centralUsed) ans += 2;
        return ans;
    }
};
