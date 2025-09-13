class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        map<char,int> mpp;
        int maxVows = 0;
        int maxCons=0;
        mpp['a']=0;mpp['e']=0;mpp['i']=0;mpp['o']=0;mpp['u']=0;
        for(auto it:s){
            if(mpp.find(it)!=mpp.end()){
                mpp[it]++;
                maxVows = max(maxVows,mpp[it]);
            }
            else{
                freq[it-'a']++;
                maxCons = max(maxCons,freq[it-'a']);
            }
        }
    
        return maxCons+maxVows;
    }
};