class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = nums[0];

        multiset<int> small, large;
        long long sumSmall = 0;

        for(int i=1;i<=dist+1;i++){
            small.insert(nums[i]);
            sumSmall+=nums[i];
            if(small.size()>k-1){
                auto it = prev(small.end());
                sumSmall-=*it;
                
                large.insert(*it);
                small.erase(it);
            }
        }
        long long best=sumSmall;
        for(int i=2;i+dist<nums.size();i++){
            if (small.find(nums[i - 1]) != small.end()) {
                sumSmall -= nums[i - 1];
                small.erase(small.find(nums[i - 1]));
            } else {
                large.erase(large.find(nums[i - 1]));
            }

            if (small.size() < k - 1 && !large.empty()) {
                auto it = large.begin(); 
                sumSmall += *it;
                small.insert(*it);
                large.erase(it);
            }

            small.insert(nums[i + dist]);
            sumSmall += nums[i + dist];

            if (small.size() > k - 1) {
                auto it = prev(small.end()); 
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }

            best = min(best, sumSmall);
        }
        return ans+best;
    }
};
