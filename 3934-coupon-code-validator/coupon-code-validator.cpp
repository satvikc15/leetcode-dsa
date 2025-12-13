class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<string,string>> ans; 
        map<string,int> mpp;
        mpp["electronics"] = 0;
        mpp["grocery"]     = 1;
        mpp["pharmacy"]    = 2;
        mpp["restaurant"]  = 3;

        for(int i = 0; i < code.size(); i++){
            string temp = code[i];
            if(temp.size() >= 1){
                bool flag = true;
                for(auto it : temp){
                    if(!isalnum((unsigned char)it) && it != '_'){
                        flag = false;
                        break;
                    }
                }
                if(flag && mpp.find(businessLine[i]) != mpp.end() && isActive[i]){
                    ans.push_back({businessLine[i], temp}); 
                }
            }
        }

        sort(ans.begin(), ans.end(), [&](auto &a, auto &b){
            
            if(mpp[a.first] != mpp[b.first])
                return mpp[a.first] < mpp[b.first];

            return a.second < b.second;
        });

        vector<string> res;   
        for(auto &it : ans){
            res.push_back(it.second);
        }

        return res;
    }
};
