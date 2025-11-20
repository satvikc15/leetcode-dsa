class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        while(true){
            if(mpp.find(original)!=mpp.end()){
                original*=2;
            }else{
                return original;
            }
        }
        return 1;
    }
};