class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> left, right;
        int total_size = nums.size();

        for (int num : nums) {
            right[num]++;
        }

        int left_size = 0;
        for (int i = 0; i < total_size; i++) {
            int num = nums[i];
            right[num]--;
            left[num]++;
            left_size++;
            int right_size = total_size - left_size;

            if (2 * left[num] > left_size && 2 * right[num] > right_size) {
                return i;
            }
        }
        return -1;
    }
};
