class Solution {
    bool solve(vector<vector<char>>& grid, int x, int y, int op, vector<vector<vector<int>>>& dp){
        if(x >= grid.size() || y >= grid[0].size()){
            return false;
        }
        if(x == grid.size() - 1 && y == grid[0].size() - 1 && op == 1 && grid[x][y] == ')'){
            return true;
        }
        
        if(dp[x][y][op] != -1){
            return dp[x][y][op];
        }

        int opog = op;

        if(grid[x][y] == '('){
            op++;
        }
        else{
            op--;
        }
        if(op < 0){
            return dp[x][y][opog] = false;
        }
        bool ans = false;
        ans = ans || solve(grid, x + 1, y, op, dp);
        ans = ans || solve(grid, x, y + 1, op, dp);

        return dp[x][y][opog] = ans;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        vector<vector<vector<int>>> dp(grid.size() + 1, vector<vector<int>>(grid[0].size() + 1, vector<int>(201, -1)));
        return solve(grid, 0, 0, 0, dp);
    }
};