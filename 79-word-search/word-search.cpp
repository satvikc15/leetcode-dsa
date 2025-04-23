class Solution {
public:
    bool fun(int ind, int i, int j, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
        if (ind == word.size()) return true;

        visited[i][j] = true;
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for (auto [a, b] : dir) {
            int ni = i + a, nj = j + b;
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && !visited[ni][nj]) {
                if (board[ni][nj] == word[ind]) {
                    if (fun(ind + 1, ni, nj, board, word, visited)) return true;
                }
            }
        }

        visited[i][j] = false; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                    if (fun(1, i, j, board, word, visited)) return true;
                }
            }
        }
        return false;
    }
};
