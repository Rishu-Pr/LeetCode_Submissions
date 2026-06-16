#define MOD 1000000007
int dp[3][1001][2001];
class Solution {
    long long solve(string& s, int prev, int idx, long long pnt){
        if(idx == s.size()){
            return (pnt > 0) ? 1 : 0;
        }
        
        if (dp[prev][idx][pnt + 1000] != -1){
            return dp[prev][idx][pnt + 1000];
        }

        long long select_E = 0;
        long long select_F = 0;
        long long select_W = 0;

        if(s[idx] == 'F'){
            if(prev != 0) select_F = solve(s, 0, idx + 1, pnt) % MOD;
            if(prev != 1) select_W = solve(s, 1, idx + 1, pnt + 1) % MOD;
            if(prev != 2) select_E = solve(s, 2, idx + 1, pnt - 1) % MOD;
        }
        else if(s[idx] == 'W'){
            if(prev != 0) select_F = solve(s, 0, idx + 1, pnt - 1) % MOD;
            if(prev != 1) select_W = solve(s, 1, idx + 1, pnt) % MOD;
            if(prev != 2) select_E = solve(s, 2, idx + 1, pnt + 1) % MOD;
        }
        else{
            if(prev != 0) select_F = solve(s, 0, idx + 1, pnt + 1) % MOD;
            if(prev != 1) select_W = solve(s, 1, idx + 1, pnt - 1) % MOD;
            if(prev != 2) select_E = solve(s, 2, idx + 1, pnt) % MOD;
        }

        return dp[prev][idx][pnt + 1000] = (select_F + select_W + select_E) % MOD;
    }
public:
    int countWinningSequences(string s) {
        memset(dp, -1, sizeof(dp));
        long long ans = (solve(s, 0, 0, 0) + solve(s, 1, 0, 0) + solve(s, 2, 0, 0)) % MOD;
        long long inv2 = (MOD + 1) / 2;
        return (ans % MOD * inv2) % MOD;
    }
};