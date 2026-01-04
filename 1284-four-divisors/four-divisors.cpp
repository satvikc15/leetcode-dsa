class Solution {
public:
    unordered_map<int,int> mpp;
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
        return mpp[n]=count==4 ? temp:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            if(mpp.find(it)==mpp.end()){
            ans+=pos(it);
            }else{
                ans+=mpp[it];
            }
        }
        return ans;
    }
};