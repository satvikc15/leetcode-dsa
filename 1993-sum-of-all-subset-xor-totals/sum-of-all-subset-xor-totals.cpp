class Solution {
public:
    int fun(int i,vector<int>& nums,int total){
        if(i==nums.size()){
            return total;
        }
        return fun(i+1,nums,total^nums[i])+fun(i+1,nums,total);
    }
    int subsetXORSum(vector<int>& nums) {
        int total=0;
        
        return fun(0,nums,total);
    }
};