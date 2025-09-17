class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(auto it:s){
            if(it==']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int n = stoi(num);
                string fin = "";
                for(int i=0;i<n;i++){fin+=temp;}
                for(auto c:fin) st.push(c);
            }else{
                st.push(it);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};