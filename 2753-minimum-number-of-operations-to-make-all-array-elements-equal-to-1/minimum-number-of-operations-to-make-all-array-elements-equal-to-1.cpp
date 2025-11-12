class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums) {
        int ones=0;
        for(auto it:nums){
            if(it==1){
                ones++;
            }
        }
        //if(ones==nums.size()) return 0;
        if(ones>=1) return nums.size()-ones;
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int n=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(j-i>=mini) break;
                n=gcd(n,nums[j]);
                if(n==1){
                    mini=j-i;
                }
            }
        }
        return mini==INT_MAX?-1:nums.size()+(mini-1);
    }
};