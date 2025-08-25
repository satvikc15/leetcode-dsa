class Solution {
public:
    int fun(int i,vector<int>& nums,int &temp){
        int flag=true;
        int k=0;
        for(int j=i;j<nums.size();j++){
            if(nums[j]==0 && flag==true){
                
                flag=false;
            }else if(nums[j]==0 && flag==false){
                break;
            }else{
                temp++;
                if(flag) k++;
            }
        }
        if(flag) temp--;
        return k;
    }
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            
                int temp=0;
                i+=fun(i,nums,temp);
                maxi=max(temp,maxi);
            
        }
        return maxi;
    }
};