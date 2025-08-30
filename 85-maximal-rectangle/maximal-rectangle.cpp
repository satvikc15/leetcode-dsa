class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> temp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            int count = 0;
            for(int j=n-1; j>=0; j--){
                if(mat[i][j] == '1'){
                    count++;
                    temp[i][j] = count;
                } else {
                    count = 0;
                }
            }
        }

        int maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == '1'){
                    int w = temp[i][j];
                    for(int k=i; k<m && mat[k][j]=='1'; k++){
                        w = min(w, temp[k][j]);
                        maxi = max(maxi, w * (k-i+1));
                    }
                }
            }
        }
        return maxi;
    }
};
