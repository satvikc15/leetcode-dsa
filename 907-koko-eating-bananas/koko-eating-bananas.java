class Solution {
    public boolean pos(int[] piles, int h,int mid){
        int count=0;
        for(int i=0;i<piles.length;i++){
            count+=Math.ceil((double)piles[i]/mid);
            if(count>h) return false;
        }
        return count<=h;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int l=1;
        int r = piles[0];
        for(int i=0;i<piles.length;i++){
            if(piles[i]>r){
                r=piles[i];
            }
        }
        while(l<=r){
            int mid = l+(r-l)/2;
            if(pos(piles,h,mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
}