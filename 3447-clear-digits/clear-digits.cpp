class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto it:s){
            if('9'<it){
                st.push(it);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};