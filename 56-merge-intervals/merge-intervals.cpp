class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            int temp=i+1;
            int end=intervals[i][1];
            while(temp < intervals.size() && end>=intervals[temp][0]){
                end=max(end,intervals[temp][1]);
                temp++;
                
            }
            merged.push_back({intervals[i][0],end});
            i=temp-1;
        }
        return merged;
    }
};