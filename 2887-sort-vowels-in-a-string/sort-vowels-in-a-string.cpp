class Solution {
public:
    bool isVow(char c){
        string ans = "AEIOUaeiou";
        for(auto it:ans){
            if(it==c) return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string ans="";
        for(auto it:s){
            if(isVow(it)){
                ans+=it;
            }
        }
        sort(ans.begin(),ans.end());
        int i=0;
        for(int ind=0;ind<s.size();ind++){
            if(isVow(s[ind])){
                s[ind]=ans[i++];
            }
        }
        return s;
    }
};