class Solution {
public:
    int totalMoney(int n) {
        if(n<=7){
            return (n*(n+1))/2;
        }
        int num = n/7;
        int t=num;
        int rem=n%7;
        int sum=0;
        int temp=28;
        while(num--){
            sum+=temp;
            temp+=7;
        }
        int i=1;
        while(rem--){
            sum+=t+i;i++;
        }
        return sum;
    }
};