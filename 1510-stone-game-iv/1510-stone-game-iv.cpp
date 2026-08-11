class Solution {
    bool solve(int n, vector<int>& dp) {
        if(dp[n] != -1){
            return dp[n];
        }
        if (n == 0) {
            return false;
        }

        int i = 1;
        bool ans = false;
        while (i * i <= n) {
            if (!solve(n - i * i, dp)) {
                ans = true;
            }
            i++;
        }

        return dp[n] = ans;
    }

public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};