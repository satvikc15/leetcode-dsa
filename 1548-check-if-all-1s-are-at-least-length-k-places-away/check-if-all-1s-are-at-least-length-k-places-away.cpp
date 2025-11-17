class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                int temp=i+1;
                int n=k;
                while(temp<nums.size() && n-->0){
                    if(nums[temp]==1){
                        return false;
                    }
                    temp++;
                }
                
            }
        }
        return true;
    }
};