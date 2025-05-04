class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> s1;
        s1.insert(nums[0]);
        int count=0;
        set<int> s2(nums.begin()+1,nums.end());
        for(int j=1;j<nums.size()-1;j++){
            if(s1.find(nums[j]-diff)!=s1.end() && s2.find(diff+nums[j])!=s2.end()) count++;
            s1.insert(nums[j]);
            s2.erase(nums[j]);
        }
        return count;
    }
};