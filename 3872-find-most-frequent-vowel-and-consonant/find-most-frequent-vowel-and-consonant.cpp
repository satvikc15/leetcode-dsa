class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        map<char,int> mpp;
        mpp['a']=0;mpp['e']=0;mpp['i']=0;mpp['o']=0;mpp['u']=0;
        for(auto it:s){
            if(mpp.find(it)!=mpp.end()){
                mpp[it]++;
            }
            else{
                freq[it-'a']++;
            }
        }
        int maxVows = 0;
        for(auto it:mpp){
            maxVows = max(maxVows,it.second);
        }
        int maxCons=0;
        for(auto it:freq){
            maxCons = max(maxCons,it);
        }
        return maxCons+maxVows;
    }
};