class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        map<string, int> mpp;
        sort(folder.begin(),folder.end());
        for (auto it : folder) {
            if (mpp.empty()) {
                mpp[it]++;
            } else {
                bool flag = true;
                for (int i = it.size(); i>0; i--) {
                    while (i >=0 && (it.substr(0, i).size() == it.size() || it[i] != '/')) {
                        i--;
                    }
                    if (mpp.find(it.substr(0, i)) != mpp.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    mpp[it]++;
                }
            }
        }
        
        for (auto it : mpp) {
            ans.push_back(it.first);
        }
        
        return ans;
    }
};