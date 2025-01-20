class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            map<int,int> mpp;
            for(int j=0;j<n;j++){
                mpp[matrix[i][j]]++;
            }
            if(mpp.size()!=n){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            map<int,int> mpp;
            for(int j=0;j<n;j++){
                mpp[matrix[j][i]]++;
            }
            if(mpp.size()!=n){
                return false;
            }
        }
        return true;
    }
};