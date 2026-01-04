class Solution {
public:
    int pos(int n){
        int count=0;
        int temp=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                count++;
                temp+=i;
            }
            if(n%(n-i+1)==0){
                count++;
                temp+=(n-i+1);
            }
            if(count>4) return 0;
        }
        return count==4 ? temp:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans+=pos(it);
        }
        return ans;
    }
};