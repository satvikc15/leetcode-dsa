class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        map<char,int> vow;
        vow['a']=1; vow['e']=0;vow['i']=1;vow['o']=1;vow['u']=1;
        vow['A']=1;vow['E']=1;vow['I']=1;vow['O']=1;vow['U']=1;
        bool vows=false;
        bool cons=false;
        for(auto it:word){
            if(!isalnum(it)){
                return false;
            }else if(vow.find(it)!=vow.end()){
                vows=true;
            }else if(isdigit(it)){
                continue;
            }else{
                cons=true;
            }
        }
        return cons&&vows;
    }
};