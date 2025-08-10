class Solution {
    public int[] rearrangeArray(int[] nums) {
        int i=0;
        int j=nums.length-1;
        int pos=0;
        int neg=nums.length-1;
        int[] ans= new int[j+1];
        while(i<nums.length){
            if(nums[i]>=0){
                ans[pos]=nums[i];
                pos+=2;
            }
            if(nums[j]<0){
                ans[neg]=nums[j];
                neg-=2;
            }
            i++;
            j--;
        }
        return ans;
    }
}