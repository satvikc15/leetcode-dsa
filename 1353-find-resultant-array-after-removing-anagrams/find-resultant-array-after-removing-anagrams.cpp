class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> st;
        vector<string> ans;
        for(auto it:words){
            string temp = it;
            sort(temp.begin(),temp.end());
            
            if(st.empty() || st.back()!=temp){
                ans.push_back(it);
            }
            st.push_back(temp);
        }
        return ans;
    }
};