class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        int n=mpp.size();
        int l=0,r=0;
        unordered_map<int,int> st; 
        int count=0;
        while(r<nums.size()){
            st[nums[r]]++;
            while(st.size()==mpp.size()){
                count+=(nums.size()-r);
                st[nums[l]]--;
                if(st[nums[l]]==0) st.erase(nums[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};