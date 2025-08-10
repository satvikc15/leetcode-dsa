class Solution {
    void swap(int[] nums,int l,int r){
        int temp=nums[l];
        nums[l]=nums[r];
        nums[r]=temp;
    }
    public void moveZeroes(int[] nums) {
        int l=0;int r=0;
        int n=nums.length;
        while(r<n){
            while(r<n && nums[r]==0){
                r++;
            }
            if(r>=n) return;
            if(nums[l]==0){
                swap(nums,l,r);
            }
            r++;
            l++;
        }
    }
}