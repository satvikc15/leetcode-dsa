class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        mpp.put(0,1);
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(mpp.containsKey(sum-k)){
                ans+=mpp.get(sum-k);
            }
            mpp.put(sum,mpp.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}