class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> n;
        int rows = mat.size(), cols = mat[0].size();
        
        for (int j = 0; j < cols; j++) {
            vector<int> temp;
            int r = 0, c = j;
            while (r < rows && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }
            if (j % 2 == 0) reverse(temp.begin(), temp.end());
            for (auto it : temp) n.push_back(it);
        }
        
        for (int i = 1; i < rows; i++) {
            vector<int> temp;
            int r = i, c = cols - 1;
            while (r < rows && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }
            if ((i + cols - 1) % 2 == 0) reverse(temp.begin(), temp.end());
            for (auto it : temp) n.push_back(it);
        }
        
        return n;
    }
};
