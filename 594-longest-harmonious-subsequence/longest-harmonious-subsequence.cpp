class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int res=0;
        for(auto it:nums){
            if(mpp[it+1]>0||mpp[it-1]>0) res = max(res,max(mpp[it]+mpp[it+1],mpp[it]+mpp[it-1]));
        }
        return res;
    }
};