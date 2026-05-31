#define MOD 1000000007
class Solution {
    long long solve(string& s, int idx, vector<long long>& dp){
        int n = s.size();
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];

        long long ways = 0;

        if(s[idx] == '*') ways = (9 * solve(s, idx+1, dp)) % MOD;
        else ways = solve(s, idx+1, dp) % MOD;

        if(idx+1 < n) {
            if(s[idx] == '*' && s[idx+1] == '*') ways = (ways + 15 * solve(s, idx+2, dp)) % MOD;
            else if(s[idx] == '*') {
                if(s[idx+1] >= '0' && s[idx+1] <= '6') ways = (ways + 2 * solve(s, idx+2, dp)) % MOD;
                else if(s[idx+1] >= '7' && s[idx+1] <= '9') ways = (ways + solve(s, idx+2, dp)) % MOD;
            }
            else if(s[idx+1] == '*') {
                if(s[idx] == '1') ways = (ways + 9 * solve(s, idx+2, dp)) % MOD;
                else if(s[idx] == '2') ways = (ways + 6 * solve(s, idx+2, dp)) % MOD;
            }
            else {
                int val = stoi(s.substr(idx, 2));
                if(val >= 10 && val <= 26) ways = (ways + solve(s, idx+2, dp)) % MOD;
            }
        }

        return dp[idx] = ways % MOD;
    }
public:
    int numDecodings(string s) {
        vector<long long> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};
