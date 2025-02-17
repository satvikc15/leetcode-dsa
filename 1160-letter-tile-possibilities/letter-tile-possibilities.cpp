class Solution {
public:
    void fun(unordered_map<char, int>& mpp, int& res) {
        for (auto& it : mpp) {
            if (it.second > 0) {
                res++;
                it.second--;
                fun(mpp, res);
                it.second++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        int res = 0;
        unordered_map<char, int> mpp;
        for (char it : tiles) {
            mpp[it]++;
        }
        fun(mpp, res);
        return res;
    }
};
