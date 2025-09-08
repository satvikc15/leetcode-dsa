class Solution {
public:
    bool pos(int i,int j){
        while(i){
            if(i%10==0) return false;
            i=i/10;
        }
        while(j){
            if(j%10==0) return false;
            j=j/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n/2;i++){
            if(pos(i,n-i)){
                return {i,n-i};
            }
        }
        return {};
    }
};