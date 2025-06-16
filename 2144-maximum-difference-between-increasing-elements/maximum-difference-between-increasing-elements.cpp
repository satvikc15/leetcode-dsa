class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n=nums.size();
        vector<int> temp(n,0);
        temp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=max(nums[i],temp[i+1]);
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,temp[i]-nums[i]);
        }
        return maxi==0?-1:maxi;
    }
};