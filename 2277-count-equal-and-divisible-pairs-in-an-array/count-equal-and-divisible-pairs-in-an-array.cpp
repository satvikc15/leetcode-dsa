class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int c=0;
        for(auto [a,b]:mpp){
            if(b.size()>1){
                for(int i=0;i<b.size();i++){
                    for(int j=i+1;j<b.size();j++){
                        if((b[i]*b[j])%k==0){
                            c++;
                        }
                    }
                }
            }
            else{
                continue;
            }
        }
        return c;
    }
};