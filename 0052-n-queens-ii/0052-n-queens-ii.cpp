class Solution {
    bool isSafe(int row, int col, vector<string>& visited){
        int x = row;
        int y = col;

        while(y >= 0){
            if(visited[x][y] == 'Q'){
                return false;
            }
            y--;
        }
        
        x = row;
        y = col;
        while(y >= 0 && x >= 0){
            if(visited[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }
        
        x = row;
        y = col;
        while(y >= 0 && x < visited.size()){
            if(visited[x][y] == 'Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    void solve(int col, vector<string>& visited, vector<vector<string>>& Ans, int n){
        if(col == n){
            Ans.push_back(visited);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, visited)){
                visited[row][col] = 'Q';
                solve(col + 1, visited, Ans, n);
                visited[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> visited;
        for(int i = 0; i < n; i++){
            string strtemp = "";
            for(int j = 0; j < n; j++){
                strtemp.push_back('.');
            }
            visited.push_back(strtemp);
        }
        vector<vector<string>> Ans;
        solve(0, visited, Ans, n);
        return Ans.size();
    }
};