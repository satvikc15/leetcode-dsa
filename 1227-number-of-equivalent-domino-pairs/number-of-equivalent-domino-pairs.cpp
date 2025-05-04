class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mpp;
        for(auto it:dominoes){
            int a = min(it[0], it[1]);
            int b = max(it[0], it[1]);
            mpp[{a, b}]++;
        }
        int count=0;
        for(auto it:mpp){
            if(it.second>1){
                count+=it.second*(it.second-1)/2;
            }
        }
        return count;
    }
};