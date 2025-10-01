class Solution {
public:
    int countPrimes(int n) {
        if(n==1 || n==2) return 0;
        //if(n==2) return 1;
        vector<bool> pos(n+1,true);
        for(int i=2;i<n;i++){
            if(pos[i]){
                for(int j=2;i*j<=n;j++)
                {
                    pos[i*j]=false;
                }
            }
        }
        
        int count=0;
        for(int i=2;i<n;i++){
            if(pos[i]==true) count++;
        }
        return count;
    }
};