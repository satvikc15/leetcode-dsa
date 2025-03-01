class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int> temp;
        for(auto it:nums){
            if(it!=0){
                temp.push_back(it);
            }
        }
        for(int i=temp.size();i<nums.size();i++){
            temp.push_back(0);
        }
        return temp;
    }
};