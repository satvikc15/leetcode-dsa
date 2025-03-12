class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int b = upper_bound(nums.begin(),nums.end(),0)-nums.begin();
        return max((int)nums.size() - b, a);
    }
};