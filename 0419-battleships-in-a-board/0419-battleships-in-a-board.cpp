class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        vector<vector<char>> temp(n + 1, vector<char>(m + 1, '.'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == n || j == m){
                    temp[i][j] = '.';
                }
                else{
                    temp[i][j] = board[i][j];
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(temp[i][j] == 'X'){
                    if(temp[i + 1][j] == '.' && temp[i][j + 1] == '.'){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};