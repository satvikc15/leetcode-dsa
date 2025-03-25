class Solution {
public:
    bool pos(vector<vector<int>> &cor){
        int count = 0;
        int end = cor[0][1]; 
        for (int i = 1; i < cor.size(); i++) {
            if (cor[i][0] >= end) { 
                count++;
            }
            end = max(end, cor[i][1]); 
            if (count >= 2) return true;
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y;
        for(auto it:rectangles){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(pos(x)){
            return true;
        }else if(pos(y)){
            return true;
        }
        return false;
    }
};