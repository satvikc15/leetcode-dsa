class Solution {
public:
    int fun(int n){
        int ans = 0;
        while(n > 0){
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int num : nums){
            mpp[fun(num)].push_back(num);
        }

        int maxi = -1;
        for(auto& it : mpp){
            if(it.second.size() > 1){
                vector<int>& v = it.second;
                sort(v.rbegin(), v.rend());
                maxi = max(maxi, v[0] + v[1]);
            }
        }
        return maxi;
    }
};
