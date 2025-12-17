class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])==mpp.end()){
                nums[ind++]=nums[i];
            }
            mpp[nums[i]]=1;
        }
        return ind;
    }
};