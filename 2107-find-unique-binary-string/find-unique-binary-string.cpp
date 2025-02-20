class Solution {
public:
    string fun(string temp, int n, unordered_map<string, int>& mpp) {
        if (temp.size() == n) {
            if (mpp.find(temp) == mpp.end()) 
                return temp;
            return "";
        }
        string res = fun(temp + '0', n, mpp);
        if (!res.empty()) return res; 
        return fun(temp + '1', n, mpp);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string, int> mpp;
        
        for (auto& it : nums) 
            mpp[it]++;
        
        return fun("", n, mpp);
    }
};
