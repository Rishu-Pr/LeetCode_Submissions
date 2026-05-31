#define MOD 1000000007
class Solution {
    int solve(string& s, int idx,vector<long long>& dp){
        int n = s.size();
        if(idx == n) return 1;
        if(idx > n || s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx] % MOD;

        if (s[idx] == '*' && s[idx + 1] == '*') return dp[idx] = (96 * (solve(s, idx + 2, dp) % MOD)) % MOD;
        if(s[idx] == '*') {
            int sum = 0;
            if(idx < n - 1 && s[idx + 1] >= '1' && s[idx + 1] <= '6') sum += 2;
            else if(idx < n - 1 && s[idx + 1] >= '7' && s[idx + 1] <= '9') sum += 1;
            return dp[idx] = ((9 + sum) * (solve(s, idx + 1, dp) % MOD)) % MOD;
        }

        int step_1 = solve(s, idx + 1, dp);
        int step_2 = 0;
        if(idx <= n - 2){
            if(s[idx + 1] == '*' && s[idx] == '1') step_2 = (9 * (solve(s, idx + 2, dp) % MOD)) % MOD;
            else if(s[idx + 1] == '*' && s[idx] == '2') step_2 = (6 * (solve(s, idx + 2, dp) % MOD)) % MOD;
            else if(stoi(s.substr(idx, 2)) <= 26 && s[idx + 1] != '*') step_2 = solve(s, idx + 2, dp);
        }
        
        return dp[idx] =  (step_1 + step_2) % MOD;
    }
public:
    int numDecodings(string s) {
        vector<long long> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};