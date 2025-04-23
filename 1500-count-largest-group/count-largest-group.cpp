class Solution {
public:
    int fun(int i){
        int sum=0;
        while(i>0){
            sum+=i%10;
            i/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int sum=fun(i);
            mpp[sum]++;
            maxi=max(mpp[sum],maxi);
        }
        int count=0;
        for(auto [a,b]:mpp){
            if(b==maxi) count++;
        }
        return count;
    }
};