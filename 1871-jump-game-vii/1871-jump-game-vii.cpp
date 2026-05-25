class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0')
            return false;

        int jumps = 0;
        vector<bool> dp(n, false);
        dp[0] = true;

        for(int i = 1; i < n; i++){
            if(i >= minJump && dp[i - minJump]) jumps++;
            if(i > maxJump && dp[i - maxJump - 1]) jumps--;
            if(s[i] == '0' && jumps > 0) dp[i] = true;
        }

        return dp[n - 1];
    }
};