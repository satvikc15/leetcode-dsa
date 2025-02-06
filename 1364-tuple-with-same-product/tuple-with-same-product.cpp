class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[i]*nums[j]]++;
            }
        }
        int count=0;
        for(auto it:mpp){
            if(it.second==2){
                count+=8;
            }
            else if(it.second>2){
                int temp=0;
                for(int k=1;k<it.second;k++){
                    temp+=k;
                }
                count=count+(temp)*8;
            }
        }
        return count;
    }
};