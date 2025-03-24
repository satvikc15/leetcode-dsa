class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());         
        int count = 0, lastMeetingEnd = 0;
        
        for (auto &it : meetings) {
            int start = it[0], end = it[1];
            
            if (start > lastMeetingEnd + 1) {
                count += (start - lastMeetingEnd - 1);
            }
            
            lastMeetingEnd = max(lastMeetingEnd, end);
        }
        
        if (lastMeetingEnd < days) {
            count += (days - lastMeetingEnd);
        }
        
        return count;
    }
};
