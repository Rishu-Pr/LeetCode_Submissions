class Solution {
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp){
        if( i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0){
            for(int k = j; k >= 0; k--)
                if(p[k] != '*') return false;
            
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        
        else if(p[j] == '*')
            return dp[i][j] = (solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp));

        else return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<int>> dp(s_size, vector<int>(p_size, -1));
        return solve(s, p, s_size - 1, p_size - 1, dp);
    }
};