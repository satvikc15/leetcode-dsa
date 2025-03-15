class Solution {
public:
    bool fun(vector<int>& nums, int k,int mid){
        int count=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                count++;
                i+=2;
            }
            else{
                i++;
            }
            if(count>=k){
                return true;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid = l+(r-l)/2;
            if(fun(nums,k,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};