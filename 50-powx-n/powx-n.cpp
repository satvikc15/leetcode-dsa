class Solution {
public:
    double pow(double x,long long n){
        if(n==0){
            return 1.0;
        }
        if(n==1){
            return x;
        }
        if(n%2==0){
            double temp = pow(x,n/2);
            return temp*temp;
        }else{
            return x*pow(x,n-1);
        }
    }
    double myPow(double x, int n) {
        long long nn=n;
        if(nn<0){
            nn=-nn;
        }
        double ans = pow(x,nn);
        if(n<0){
            return (double)1/ans;
        }
        return ans;
    }
};