class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if((n&(n-1))==0) return true;
        string num = to_string(n);
        sort(num.begin(),num.end());
        set<string> st;
        for(int i=1;i<=1e9;i*=2){
            string temp = to_string(i);
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        if(st.find(num)!=st.end()) return true;
        else return false;
    }
};