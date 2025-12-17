class Solution {
public:
    void fun(int i, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target<0) return;
        temp.push_back(candidates[i]);
        fun(i+1, candidates, target - candidates[i], temp, ans);
        temp.pop_back();

        int j = i+1;
        while (j < candidates.size() && candidates[j] == candidates[i]) j++;

        fun(j, candidates, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0, candidates, target, temp, ans);
        return ans;
    }
};
