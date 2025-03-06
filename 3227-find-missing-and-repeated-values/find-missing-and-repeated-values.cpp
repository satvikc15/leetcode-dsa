class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp;
        for(auto it:grid){
            for(auto f:it){
                mpp[f]++;
            }
        }
        vector<int> ans(2,0);
        for(int i=1;i<=grid.size()*grid.size();i++){
            if(mpp.find(i)==mpp.end()){
                ans[1]=i;
            }
            if(mpp[i]==2){
                ans[0]=i;
            }
        }
        return ans;
    }
};