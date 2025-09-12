class Solution {
public:
    int fun(string s){
        map<char,int> mpp;
        int count=0;
        mpp['a']=1;mpp['e']=1; mpp['i']=1;mpp['o']=1;mpp['u']=1;
        for(auto it:s){
            if(mpp.find(it)!=mpp.end()){
                count++;
                //cout << it << endl;
            }
        }
        return count;
    }
    bool doesAliceWin(string s) {
        int vow = fun(s);
        //cout << vow << endl;
        if(vow!=0){
            return true;
        }else{
            return false;
        }
    }
};