class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n<3) return n;
        map<int,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        for(auto a:mpp){
            while(a.second>=3){ n-=2;
                a.second-=2;
                if(a.second==0){
                    mpp.erase(a.first);
                }
            }
        }
        return n;
    }
};