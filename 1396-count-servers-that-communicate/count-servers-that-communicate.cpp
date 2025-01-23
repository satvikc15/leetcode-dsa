class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<int,int> row,col;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((row[i]>1 || col[j]>1) && grid[i][j]){
                    //cout << i << " " << j << endl;
                    count++;
                }
            }
        }
        return count;
    }
};