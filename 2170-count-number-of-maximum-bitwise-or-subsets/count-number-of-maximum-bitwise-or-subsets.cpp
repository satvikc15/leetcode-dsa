class Solution {
public:
    void fun(int i, vector<int>& nums, int temp, int maxi, int& count) {
        if(i == nums.size()) {
            if(temp == maxi) count++;
            return;
        }
        fun(i+1, nums, temp | nums[i], maxi, count);
        fun(i+1, nums, temp, maxi, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0, count = 0;
        for(int x : nums) maxi |= x; 
        fun(0, nums, 0, maxi, count);
        return count;
    }
};
