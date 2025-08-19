class Solution {
public:
    void fun(int i, vector<int>& candidates, int target, vector<int>& temp, set<vector<int>>& ans) {
        if (target == 0) {                 
            ans.insert(temp);
            return;
        }
        if (i == candidates.size() || target < 0) return;

        temp.push_back(candidates[i]);
        fun(i+1, candidates, target - candidates[i], temp, ans);
        temp.pop_back();

        int j = i+1;
        while (j < candidates.size() && candidates[j] == candidates[i]) j++;

        fun(j, candidates, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
        set<vector<int>> ans;
        vector<int> temp;
        fun(0, candidates, target, temp, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
