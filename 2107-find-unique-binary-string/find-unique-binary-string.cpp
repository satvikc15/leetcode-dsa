class Solution {
public:
    void fun(string temp,int n,unordered_map<string,int>&mpp){
        if(temp.size()==n){
            mpp[temp]=1;
            return;
        }
        for(int i=0;i<=1;i++){
            fun(temp+char(i+'0'),n,mpp);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_map<string,int> mpp;
        fun("",n,mpp);
        for(auto it:nums)
        {
            mpp[it]--;
        }
        for(auto it:mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return "";
    }
};