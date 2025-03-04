class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i=0;
        while(pow(3,i)<=n){
            i++;
        }
        while(i-1>=0 && n>0){
            if(pow(3,i-1)<=n) n=n-pow(3,i-1);
            if(n==0) return true;
            i--;
        }
        return false;
    }
};