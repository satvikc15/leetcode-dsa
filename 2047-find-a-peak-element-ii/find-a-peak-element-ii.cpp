class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                bool flag = true;
                if(i>0){
                    if(mat[i-1][j]>mat[i][j]){
                        continue;
                    }
                }
                if(j>0){
                   if(mat[i][j-1]>mat[i][j]){
                        continue;
                    } 
                }
                if(i<mat.size()-1){
                    if(mat[i+1][j]>mat[i][j]){
                        continue;
                    }
                }
                if(j<mat[0].size()-1){
                    if(mat[i][j+1]>mat[i][j]){
                        continue;
                    }
                }
                return {i,j};
            }
        }
        return {0,0};
    }
};