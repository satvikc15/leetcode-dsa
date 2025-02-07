class Solution {
public:
    int fun(int s){
        int ans=0;
        while(s>0){
            ans+=s%10;
            s=s/10;
        }
        return ans;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int,int> mpp;
        int maxi=0;
        for(int i=lowLimit;i<=highLimit;i++){
            int sum=i;
            if(i>=10){
                sum=fun(sum);
            }
            mpp[sum]++;
            maxi=max(maxi,mpp[sum]);
        }
        return maxi;
    }
};