class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> V(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int c1 = 0;
                int c0 = 0;
                int curr = board[i][j];

                if(i >= 1 && j >= 1 && board[i - 1][j - 1] == 1){
                    c1++;
                }
                else c0++;

                if(i >= 1 && j >= 0 && board[i - 1][j] == 1){
                    c1++;
                }
                else c0++;

                if(i >= 1 && j < board[0].size() - 1 && board[i - 1][j + 1] == 1){
                    c1++;
                }
                else c0++;

                if(j >= 1 && board[i][j - 1] == 1){
                    c1++;
                }
                else c0++;

                if(j < board[0].size() - 1 && board[i][j + 1] == 1){
                    c1++;
                }
                else c0++;

                if(i < board.size() - 1 && j >= 1 && board[i + 1][j - 1] == 1){
                    c1++;
                }
                else c0++;

                if(i < board.size() - 1 && board[i + 1][j] == 1){
                    c1++;
                }
                else c0++;

                if(i < board.size() - 1 && j < board[0].size() - 1 && board[i + 1][j + 1] == 1){
                    c1++;
                }
                else c0++;

                if(curr == 1 && (c1 == 2 || c1 == 3)){
                    V[i][j] = 1;
                }
                else if(curr == 0 && c1 == 3){
                    V[i][j] = 1;
                }
                else{
                    V[i][j] = 0;
                }
            }
        }

        board = V;
    }
};