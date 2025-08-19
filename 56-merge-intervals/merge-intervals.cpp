class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        // int start=intervals[0][0];
        // int end = intervals[0][1];
        for(int i=0;i < intervals.size();i++){
            int start=intervals[i][0];
            int end = intervals[i][1];
            int j=i+1;
            while(j<intervals.size() && intervals[j][0]<=end){
                end = max(end,intervals[j][1]);
                j++;
            }
            ans.push_back({start,end});
            i=j-1;
        }
        return ans;
    }
};