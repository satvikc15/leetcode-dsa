class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        
        for (int num : nums) {
            int r = ((num % value) + value) % value; 
            freq[r]++;
        }

        int x = 0;
        while (true) {
            int r = x % value;
            if (freq[r] > 0) freq[r]--;
            else return x; 
            x++;
        }
    }
};
