class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            bool flag=true;
            int count1=0,count2=0,count=0;
            for(int j=i;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count1++;
                    count2++;
                }else if((nums[i]-nums[j])==1){
                    flag=false;
                    count1++;
                }else if((nums[i]-nums[j])==-1){
                    flag=false;
                    count2++;
                }
            }
            count = max(count1,count2);
            if(!flag) maxi=max(count,maxi);
        }
        return maxi;
    }
};