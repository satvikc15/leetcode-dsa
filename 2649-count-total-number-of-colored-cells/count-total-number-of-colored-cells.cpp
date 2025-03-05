class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0LL;
        for(int i=0;i<n-1;i++){
            ans+=2*i+1LL;
        }
        
        for(int i=n-1;i>=0;i--){
            ans+=2*i+1LL;
        }
        return ans;
    }
};