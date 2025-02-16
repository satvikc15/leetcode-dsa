class Solution {
public:
    bool fun(int i,vector<int> &res,int n,unordered_map<int,int>&mpp){
        if(i==res.size()){
            return true;
        }
        for(int k=n;k>0;k--){
            if(mpp.find(k)!=mpp.end()) continue;
            if(k>1 && (i+k>=res.size() || res[i+k]!=-1)) continue;
            mpp[k]++;
            res[i]=k;
            if(k>1) res[i+k]=k;
            int j=i+1;
            while(j<res.size()&&res[j]!=-1){
                j++;
            }
            if(fun(j,res,n,mpp)){
                return true;
            }
            mpp.erase(k);
            res[i]=-1;
            if(k>1) res[i+k]=-1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2*n-1,-1);
        unordered_map<int,int> mpp;
        fun(0,res,n,mpp);
        return res;
    }
};