class Solution {
    bool solve(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int idx_X, int idx_Y, int idx_w){
        if(idx_w == word.size()){
            return true;
        }
        if (idx_X < 0 || idx_X >= board.size() || idx_Y < 0 || idx_Y >= board[0].size() || 
            visited[idx_X][idx_Y] || board[idx_X][idx_Y] != word[idx_w]) {
            return false;
        }
        bool ans = false;
        
        visited[idx_X][idx_Y] = 1;
        ans = ans || solve(board, visited, word, idx_X - 1, idx_Y, idx_w + 1);
        ans = ans || solve(board, visited, word, idx_X + 1, idx_Y, idx_w + 1);
        
        ans = ans || solve(board, visited, word, idx_X, idx_Y  - 1, idx_w + 1);
        ans = ans || solve(board, visited, word, idx_X, idx_Y + 1, idx_w + 1);
        
        visited[idx_X][idx_Y] = 0;
        
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        bool ans = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                ans = ans || solve(board, visited, word, i, j, 0);
            }
        }

        return ans;
    }
};