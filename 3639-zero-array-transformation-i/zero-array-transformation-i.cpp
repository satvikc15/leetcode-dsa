class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> temp(nums.size()+1,0);
        for(auto it:queries){
            temp[it[0]]--;
            temp[it[1]+1]++;
        }
        int t=0;
        for(int i=0;i<nums.size();i++){
            t+=temp[i];
            nums[i]+=t;
            if(nums[i]<0) nums[i]=0;
            cout << nums[i] << " ";
        }
        for(auto it:nums){
            if(it!=0) return false;
        }
        return true;
    }
};