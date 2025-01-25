class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> temp(nums.begin(), nums.end());
        sort(nums.begin(),nums.end());
        vector<queue<int>> t;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            queue<int> q;
            q.push(nums[i]);
            mpp[nums[i]] = t.size();
            while (i < nums.size() - 1 && abs(nums[i] - nums[i + 1]) <= limit) {
                q.push(nums[i + 1]);
                mpp[nums[i + 1]] = t.size();
                i++;
            }
            t.push_back(q);
        }
        for (int i = 0; i < nums.size(); i++) {
            int k = mpp[temp[i]];
            temp[i] = t[k].front();
            t[k].pop();
        }
        return temp;
    }
};
