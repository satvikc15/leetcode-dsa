class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1LL;
        int count=0;
        for(auto it:nums){
            if(it!=0) prod*=it;
            else count++;
        }
        vector<int> ans;
        for(auto it:nums){
            if(it==0 && count<2 && count!=nums.size()){
                ans.push_back(prod);
            }else if(count==0){
                ans.push_back(prod/it);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};