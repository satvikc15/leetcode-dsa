class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> words(26);
        map<int,int> ri;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                words[s[i]-'a'].push(i);
            }else{
                ri[i]++;;
                for(int i=0;i<26;i++){
                    if(!words[i].empty()){
                        ri[words[i].top()]++;
                        words[i].pop();
                        break;
                    }
                }
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(ri.find(i)==ri.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};