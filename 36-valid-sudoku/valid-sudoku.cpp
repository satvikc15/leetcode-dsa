class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,set<char>> row, col;
        map<pair<int,int>, set<char>> sq;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                char c = board[i][j];

                if(row[i].find(c) != row[i].end() ||
                   col[j].find(c) != col[j].end() ||
                   sq[{i/3, j/3}].find(c) != sq[{i/3, j/3}].end()) {
                    return false;
                }

                row[i].insert(c);
                col[j].insert(c);
                sq[{i/3, j/3}].insert(c);
            }
        }
        return true;
    }
};
